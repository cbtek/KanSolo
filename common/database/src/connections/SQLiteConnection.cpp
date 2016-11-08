#include "connections/SQLiteConnection.h"

#include "utility/inc/Exception.hpp"
using namespace cbtek::common::utility;

namespace cbtek {
namespace common {
namespace database {
namespace connections{

CREATE_EXCEPTION(SQLiteConnectionException, "SQLite Connection Exception Occured")

SQLiteConnection::SQLiteConnection()
{
    m_database=NULL;
}

SQLiteConnection::SQLiteConnection(const std::string &connectionURL,
                                   const std::string &userName,
                                   const std::string &password)
{
    connect(connectionURL,userName,password);
}

bool SQLiteConnection::connect(const std::string &connectionURL,
                               const std::string &userName,
                               const std::string &password)
{

    try
    {
        m_username = userName;
        m_password = password;
        checkErrorCode(sqlite3_open(connectionURL.c_str(),&m_database));
        m_currentConnectionString = connectionURL;
        return true;

    }
    catch(...)
    {        
        disconnect();        
        return false;
    }
}

void SQLiteConnection::disconnect()
{
    checkErrorCode(sqlite3_close(m_database));
}

QueryResultPtr SQLiteConnection::query(const std::string &query)
{    
    m_currentQuery = query;
    if (m_database)
    {        
        try
        {            
            checkErrorCode(m_result.execute(m_database,query));
        }
        catch(std::exception & e)
        {
            std::cerr<<e.what()<<std::endl;            
        }
    }    
    return std::make_shared<results::SQLiteQueryResult>(m_result);
}

void SQLiteConnection::getQueryEnclosureFormatStrings(QueryEnclosureFormatType type, std::string &beginOut, std::string &endOut)
{
    switch(type)
    {
        case QueryEnclosureFormatType::IDENTIFIER:beginOut = "`";endOut="`";break;
        case QueryEnclosureFormatType::LITERAL:beginOut = "'";endOut="'";break;
        case QueryEnclosureFormatType::TABLE:beginOut = "'";endOut="'";break;
        default: break;
    }
}

QueryResultPtr SQLiteConnection::query(const std::string &query, const std::uint64_t & ndx)
{
    m_currentQuery = query;
    if (m_database)
    {
        try
        {
            checkErrorCode(m_result.execute(m_database,query,ndx));
        }
        catch(std::exception & e)
        {
            std::cerr<<e.what()<<std::endl;
        }
    }
    return std::make_shared<results::SQLiteQueryResult>(m_result);
}

void SQLiteConnection::checkErrorCode(const int &errorCode)
{
    switch(errorCode)
    {    
        case SQLITE_OK:return;break;
        case SQLITE_NOTICE:return ;break;/* Notifications from sqlite3_log() */
        case SQLITE_WARNING:return ;break;/* Warnings from sqlite3_log() */
        case SQLITE_ROW: return;break;   /* sqlite3_step() has another row ready */
        case SQLITE_DONE:return;break;  /* sqlite3_step() has finished executing */
        default:throw SQLiteConnectionException(EXCEPTION_TAG+std::string(sqlite3_errstr(errorCode))+"\nThe following query generated this error: \n"+m_currentQuery+"\nThe database connection:\n"+m_currentConnectionString);
    }
}

}}}}//namespace
