//#-------------------------------------------------
//#
//# File SQLiteQueryResult.cpp created by shadowefusion on 01-11-2014 at 3:5:47
//#
//#-------------------------------------------------

#include "SQLiteQueryResult.h"

namespace cbtek {
namespace common {
namespace database {
namespace results {

SQLiteQueryResult::SQLiteQueryResult()
{

}

int SQLiteQueryResult::execute(sqlite3 *db, const std::string &query)
{
    sqlite3_stmt * statement=NULL;
    const char * unused=NULL;
    m_queryType = database::queryTypes::getQueryTypeFromString(query);
    m_lastError = sqlite3_prepare(db,query.c_str(),query.size(),&statement,&unused);
    m_resultData.clear();
    if (m_lastError==SQLITE_OK)
    {
        int columnCount = sqlite3_column_count(statement);
        m_headers.clear();
        for (size_t a1 = 0;a1<(size_t)columnCount;++a1)
        {
            m_headers.push_back(std::string((const char *)(sqlite3_column_name(statement,a1))));
        }

        int mode = sqlite3_step(statement);
        size_t rowCount=0;
        while(mode==SQLITE_ROW)
        {
            ++rowCount;
            ResultDataRow rowData;
            rowData.setHeaders(m_headers);
            for (size_t a1 = 0;a1<(size_t)columnCount;++a1)
            {
                switch (sqlite3_column_type(statement,a1))
                {
                    case SQLITE_INTEGER:
                        rowData << types::Int64Type(sqlite3_column_int64(statement,a1));
                    break;

                    case SQLITE_FLOAT:
                        rowData << types::Float64Type(sqlite3_column_double(statement,a1));
                    break;

                    case SQLITE_BLOB:

                    break;

                    case SQLITE_NULL:
                        rowData << types::NullType();
                    break;

                    case SQLITE3_TEXT:
                    {
                         std::string text=std::string((const char *)(sqlite3_column_text(statement,a1)));
                         rowData<<text;
                    }
                    break;
                default:
                    break;
                }
            }
            m_resultData.push_back(rowData);
            mode = sqlite3_step(statement);
            if(mode!=SQLITE_ROW)
            {
                break;
            }
        }
    }
    return m_lastError;
}

int SQLiteQueryResult::execute(sqlite3 *db, const std::string &query, const std::uint64_t &row)
{
    sqlite3_stmt * statement=NULL;
    const char * unused=NULL;
    m_queryType = database::queryTypes::getQueryTypeFromString(query);
    m_lastError = sqlite3_prepare(db,query.c_str(),query.size(),&statement,&unused);
    m_resultData.clear();
    if (m_lastError==SQLITE_OK)
    {
        int columnCount = sqlite3_column_count(statement);
        m_headers.clear();
        for (size_t a1 = 0;a1<(size_t)columnCount;++a1)
        {
            m_headers.push_back(std::string((const char *)(sqlite3_column_name(statement,a1))));
        }

        int mode = sqlite3_step(statement);
        size_t rowCount=0;
        while(mode==SQLITE_ROW)
        {

            ++rowCount;
            if (rowCount==(row+1))
            {
                ResultDataRow rowData;
                rowData.setHeaders(m_headers);
                for (size_t a1 = 0;a1<(size_t)columnCount;++a1)
                {
                    switch (sqlite3_column_type(statement,a1))
                    {
                        case SQLITE_INTEGER:
                            rowData << types::Int64Type(sqlite3_column_int64(statement,a1));
                        break;

                        case SQLITE_FLOAT:
                            rowData << types::Float64Type(sqlite3_column_double(statement,a1));
                        break;

                        case SQLITE_BLOB:

                        break;

                        case SQLITE_NULL:
                            rowData << types::NullType();
                        break;

                        case SQLITE3_TEXT:
                        {
                             std::string text=std::string((const char *)(sqlite3_column_text(statement,a1)));
                             rowData<<text;
                        }
                        break;
                    default:
                        break;
                    }
                }
                m_resultData.push_back(rowData);                
            }
            mode = sqlite3_step(statement);
            if(mode!=SQLITE_ROW)
            {
                break;
            }
        }
    }
    return m_lastError;
}

queryTypes::QueryType SQLiteQueryResult::getQueryType() const
{
    return m_queryType;
}

bool SQLiteQueryResult::isValid() const
{
    return m_lastError == SQLITE_OK?true:false;
}

size_t SQLiteQueryResult::getNumResultRows() const
{
    return m_resultData.size();
}

ResultDataRow SQLiteQueryResult::getResultRow(const size_t &ndx) const
{
    return ndx < m_resultData.size() ?m_resultData[ndx]:ResultDataRow();
}

int SQLiteQueryResult::getLastError() const
{
    return m_lastError;
}

std::vector<std::string> SQLiteQueryResult::getResultHeaders() const
{
    return m_headers;
}

}}}} //namespace
