/*
    KanSoloProjectManager.cpp
    
///
/// CBTek LLC ("COMPANY") CONFIDENTIAL
/// Copyright (c) 2016 CBTek, All Rights Reserved.
///
/// NOTICE:  All information contained herein is, and remains the property of COMPANY. The intellectual and technical concepts contained
/// herein are proprietary to COMPANY and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret or copyright law.
/// Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
/// from COMPANY.  Access to the source code contained herein is hereby forbidden to anyone except current COMPANY employees, managers or contractors who have executed
/// Confidentiality and Non-disclosure agreements explicitly covering such access.
///
/// The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes
/// information that is confidential and/or proprietary, and is a trade secret, of  COMPANY.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
/// OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
/// LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
/// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
///

*/
//----------------------------------------
//KanSoloProjectManager.cpp generated by cbtek on 09-13-2016 at 12:53:24 PM
//----------------------------------------

#include <iostream>

#include "KanSoloProjectManager.h"

#include "utility/inc/DateTimeUtils.hpp"
#include "utility/inc/Exception.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/XMLUtils.h"
#include "utility/inc/SystemUtils.hpp"

#include "database/inc/QueryBuilder.h"
#include "database/inc/QueryResult.hpp"


using namespace cbtek::common::utility;

namespace cbtek {
namespace products {
namespace kan_solo {

CREATE_EXCEPTION(InvalidProjectException,"KanSoloProject could not be found")
CREATE_EXCEPTION(ThemeIndexNotFoundException, "Theme index was not found")
CREATE_EXCEPTION(BoardIndexNotFoundException, "Board index was not found")

KanSoloProjectManager KanSoloProjectManager::m_instance = KanSoloProjectManager();


KanSoloProjectManager & KanSoloProjectManager::inst()
{
    return m_instance;
}


std::vector<KanSoloBoard> KanSoloProjectManager::getBoards() const
{
    std::vector<KanSoloBoard> boards;
    QueryBuilder qb;

    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    qb["@table"]=tbBeg+"boards"+tbEnd;
    qb["@id"]=idBeg+ "id"+idEnd;
    qb["@title"]=idBeg+ "title"+idEnd;
    qb["@backTitle"]=idBeg+ "backlog_title"+idEnd;
    qb["@procTitle"]=idBeg+ "processing_title"+idEnd;
    qb["@testTitle"]=idBeg+ "testing_title"+idEnd;
    qb["@finishedTitle"]=idBeg+ "finished_title"+idEnd;
    qb["@procCount"]=idBeg+ "processing_count"+idEnd;
    qb["@testCount"]=idBeg+ "testing_count"+idEnd;
    qb["@date"]=idBeg+ "board_creation_date"+idEnd;
    qb["@time"]=idBeg+ "board_creation_time"+idEnd;

    std::string query = "SELECT * FROM @table;";
    query = qb.buildQuery(query);
    qb.clean(idBeg);
    qb.clean(idEnd);
    QueryResultPtr results = m_connection->query(query);
    if (results->isValid())
    {
        int count = results->getNumResultRows();
        for (size_t a1 = 0;a1 < count; ++a1)
        {
            ResultDataRow dataRow = results->getResultRow(a1);
            KanSoloBoard board;
            board.setId(dataRow.getText(qb["@id"]));
            board.setTitle(dataRow.getText(qb["@title"]));
            board.setCreationDate(dataRow.getInteger(qb["@date"]));
            board.setCreationTime(dataRow.getInteger(qb["@time"]));
            board.setBacklogTitle(dataRow.getText(qb["@backTitle"]));
            board.setProcessingTitle(dataRow.getText(qb["@procTitle"]));
            board.setFinishedTitle(dataRow.getText(qb["@finishedTitle"]));
            board.setTestingTitle(dataRow.getText(qb["@testTitle"]));
            board.setTestingCount(dataRow.getInteger(qb["@testCount"]));
            board.setProcessingCount(dataRow.getInteger(qb["@procCount"]));
            boards.push_back(board);

        }
    }
    return boards;
}

std::vector<KanSoloTask> KanSoloProjectManager::getTasks(const std::string &boardId) const
{
    std::vector<KanSoloTask> tasks;
    QueryBuilder qb;
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    qb["@table"]=tbBeg+"tasks"+tbEnd;
    qb["@id"]=idBeg+ "id"+idEnd;
    qb["@boardId"]=idBeg+ "board_id"+idEnd;
    qb["@title"]=idBeg+ "title"+idEnd;
    qb["@desc"]=idBeg+ "description"+idEnd;
    qb["@score"]=idBeg+ "score"+idEnd;
    qb["@state"]=idBeg+ "state"+idEnd;
    qb["@size"]=idBeg+ "size"+idEnd;
    qb["@priority"]=idBeg+ "priority"+idEnd;
    qb["@creator"]=idBeg+ "creator"+idEnd;
    qb["@assignee"]=idBeg+ "assignee"+idEnd;
    qb["@createDate"]=idBeg+ "create_date"+idEnd;
    qb["@updateDate"]=idBeg+ "update_date"+idEnd;
    qb["@closeDate"]=idBeg+ "close_date"+idEnd;
    qb["@createTime"]=idBeg+ "create_time"+idEnd;
    qb["@updateTime"]=idBeg+ "update_time"+idEnd;
    qb["@closeTime"]=idBeg+ "close_time"+idEnd;
    qb["@scaleX"]=idBeg+ "scale_x"+idEnd;
    qb["@scaleY"]=idBeg+ "scale_y"+idEnd;
    qb["@boardIdValue"] = litBeg+boardId+litEnd;
    std::string query = "SELECT * from @table WHERE @boardId = @boardIdValue;";
    query = qb.buildQuery(query);

    QueryResultPtr results = m_connection->query(query);
    qb.clean(idBeg);
    qb.clean(idEnd);
    if (results->isValid())
    {
        int count = results->getNumResultRows();
        for (size_t a1 = 0;a1 < count; ++a1)
        {
            ResultDataRow dataRow = results->getResultRow(a1);
            KanSoloTask task;
            task.setId(dataRow.getText(qb["@id"]));
            task.setTitle(dataRow.getText(qb["@title"]));
            task.setCreationDate(dataRow.getInteger(qb["@createDate"]));
            task.setCreationTime(dataRow.getInteger(qb["@createTime"]));
            task.setUpdateDate(dataRow.getInteger(qb["@updateDate"]));
            task.setUpdateTime(dataRow.getInteger(qb["@updateTime"]));
            task.setCloseDate(dataRow.getInteger(qb["@closeDate"]));
            task.setCloseTime(dataRow.getInteger(qb["@closeTime"]));
            task.setDescription(dataRow.getText(qb["@desc"]));
            task.setCreator(dataRow.getText(qb["@creator"]));
            task.setAssignee(dataRow.getText(qb["@assignee"]));
            task.setScore(dataRow.getInteger(qb["@score"]));            
            task.setState(static_cast<TaskState>(dataRow.getInteger(qb["@state"])));
            task.setCardSize(static_cast<TaskCardSize>(dataRow.getInteger(qb["@size"])));
            task.setPriority(static_cast<TaskPriority>(dataRow.getInteger(qb["@priority"])));
            task.setScaleX(dataRow.getNumeric(qb["@scaleX"]));
            task.setScaleY(dataRow.getNumeric(qb["@scaleY"]));
            tasks.push_back(task);

        }
    }
    return tasks;
}

void KanSoloProjectManager::createTask(const KanSoloTask &task)
{
    QueryBuilder qb;
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    qb["@table"]=tbBeg+"tasks"+tbEnd;
    qb["@id"]=idBeg+ "id"+idEnd;
    qb["@boardId"]=idBeg+ "board_id"+idEnd;
    qb["@title"]=idBeg+ "title"+idEnd;
    qb["@desc"]=idBeg+ "description"+idEnd;
    qb["@score"]=idBeg+ "score"+idEnd;
    qb["@state"]=idBeg+ "state"+idEnd;
    qb["@size"]=idBeg+ "size"+idEnd;
    qb["@priority"]=idBeg+ "priority"+idEnd;
    qb["@creator"]=idBeg+ "creator"+idEnd;
    qb["@assignee"]=idBeg+ "assignee"+idEnd;
    qb["@createDate"]=idBeg+ "create_date"+idEnd;
    qb["@updateDate"]=idBeg+ "update_date"+idEnd;
    qb["@closeDate"]=idBeg+ "close_date"+idEnd;
    qb["@createTime"]=idBeg+ "create_time"+idEnd;
    qb["@updateTime"]=idBeg+ "update_time"+idEnd;
    qb["@closeTime"]=idBeg+ "close_time"+idEnd;
    qb["@scaleX"]=idBeg+ "scale_x"+idEnd;
    qb["@scaleY"]=idBeg+ "scale_y"+idEnd;

    std::string query="INSERT INTO @table";
    query +="(@id,@boardId,@title,@desc,"
            "@score,@state,@size,@priority,@creator,@assignee,@createDate,"
            "@updateDate,@closeDate,@createTime,@updateTime,@closeTime,@scaleX,@scaleY) VALUES(";

    query = qb.buildQuery(query);
    query+=litBeg+task.getId()+litEnd+",";
    query+=litBeg+task.getBoardId()+litEnd+",";
    query+=litBeg+XMLUtils::getEncodedString(task.getTitle())+litEnd+",";
    query+=litBeg+XMLUtils::getEncodedString(task.getDescription())+litEnd+",";
    query+= StringUtils::toString(task.getScore())+",";
    query+= StringUtils::toString(static_cast<int>(task.getState()))+",";
    query+= StringUtils::toString(static_cast<int>(task.getCardSize()))+",";
    query+= StringUtils::toString(static_cast<int>(task.getPriority()))+",";

    query+=litBeg+task.getCreator()+litEnd+",";
    query+=litBeg+task.getAssignee()+litEnd+",";

    query+= StringUtils::toString(task.getCreateDate())+",";
    query+= StringUtils::toString(task.getUpdateDate())+",";
    query+= StringUtils::toString(task.getCloseDate())+",";
    query+= StringUtils::toString(task.getCreateTime())+",";
    query+= StringUtils::toString(task.getUpdateTime())+",";
    query+= StringUtils::toString(task.getCloseTime())+",";
    query+= StringUtils::toString(task.getScaleX(),12)+",";
    query+= StringUtils::toString(task.getScaleY(),12)+");";
    m_connection->query(query);
}

void KanSoloProjectManager::removeTask(const std::string &boardId,
                                       const std::string &taskId)
{
    QueryBuilder qb;
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);
    qb["@table"] = tbBeg+"tasks"+tbEnd;
    qb["@id"] = idBeg+"id"+idEnd;
    qb["@boardId"] = idBeg+"board_id"+idEnd;
    std::string query = qb.buildQuery("DELETE FROM @table WHERE @id = "+litBeg+taskId+litEnd+" AND @boardId = "+litBeg+boardId+litEnd+";");
    //std::cerr <<query<<std::endl;
    m_connection->query(query);
}

void KanSoloProjectManager::updateTask(const std::string &boardId,
                                       const KanSoloTask &task)
{
    removeTask(boardId,task.getId());
    createTask(task);
}

void KanSoloProjectManager::createBoard(const KanSoloBoard &board)
{
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    QueryBuilder qb;
    qb["@table"]=tbBeg+"boards"+tbEnd;
    qb["@id"]=idBeg+ "id"+idEnd;
    qb["@title"]=idBeg+ "title"+idEnd;
    qb["@backTitle"]=idBeg+ "backlog_title"+idEnd;
    qb["@procTitle"]=idBeg+ "processing_title"+idEnd;
    qb["@testTitle"]=idBeg+ "testing_title"+idEnd;
    qb["@finishedTitle"]=idBeg+ "finished_title"+idEnd;
    qb["@procCount"]=idBeg+ "processing_count"+idEnd;
    qb["@testCount"]=idBeg+ "testing_count"+idEnd;
    qb["@date"]=idBeg+ "board_creation_date"+idEnd;
    qb["@time"]=idBeg+ "board_creation_time"+idEnd;

    std::string query = "INSERT INTO @table (@id,@title,@backTitle,@procTitle,@testTitle,@finishedTitle,@procCount,@testCount,@date,@time) VALUES (";
    query = qb.buildQuery(query);
    query += litBeg+board.getId()+litEnd+",";
    query += litBeg+board.getTitle()+litEnd+",";
    query += litBeg+board.getBacklogTitle()+litEnd+",";
    query += litBeg+board.getProcessingTitle()+litEnd+",";
    query += litBeg+board.getTestingTitle()+litEnd+",";
    query += litBeg+board.getFinishedTitle()+litEnd+",";
    query += StringUtils::toString(board.getProcessingCount())+",";
    query += StringUtils::toString(board.getTestingCount())+",";
    query += StringUtils::toString(board.getCreationDate())+",";
    query += StringUtils::toString(board.getCreationTime())+");";
    m_connection->query(query);

}

void KanSoloProjectManager::removeBoard(const std::string &boardId,
                                        TaskCleanupStrategy cleanupStrategy)
{
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    QueryBuilder qb;
    qb["@table"]=tbBeg+"boards"+tbEnd;
    qb["@boardId"]=idBeg+"id"+idEnd;
    m_connection->query(qb.buildQuery("DELETE FROM @table WHERE @boardId = "+litBeg+boardId+litEnd+";"));

    if (cleanupStrategy == TaskCleanupStrategy::DELETE_ASSOCIATED_TASKS)
    {
        qb.clear();
        qb["@table"]=tbBeg+"tasks"+tbEnd;
        qb["@boardId"]=idBeg+"board_id"+idEnd;
        m_connection->query(qb.buildQuery("DELETE FROM @table WHERE @boardId = "+litBeg+boardId+litEnd+";"));
    }
    else if (cleanupStrategy == TaskCleanupStrategy::UNASSIGN_ASSOCIATED_TASKS)
    {
        qb.clear();
        qb["@table"]=tbBeg+"tasks"+tbEnd;
        qb["@boardId"]=idBeg+"board_id"+idEnd;
        m_connection->query(qb.buildQuery("UPDATE @table SET @boardId = '' WHERE @boardId = "+litBeg+boardId+litEnd+";"));
    }

}

void KanSoloProjectManager::updateBoard(const KanSoloBoard &board)
{
    removeBoard(board.getId(),TaskCleanupStrategy::LEAVE_TASKS_ALONE);
    createBoard(board);
}

std::vector<KanSoloTheme> KanSoloProjectManager::getThemes() const
{

    std::vector<std::string>folders;
    std::string path =FileUtils::buildFilePath(FileUtils::getCurrentPath(),"themes");
    FileUtils::getFileEntries(path,true,std::vector<std::string>(),folders);
    std::vector<KanSoloTheme>  themes;
    for(std::string folder : folders)
    {
        KanSoloTheme theme;
        if (StringUtils::endsWith(folder,"..") || StringUtils::endsWith(folder,"."))
        {
            continue;
        }
        std::vector<std::string> themeItems;
        FileUtils::getFileEntries(folder,false,std::vector<std::string>(),themeItems);

        try
        {
            size_t newTaskNdx = StringUtils::indexOf("imgNewTask.png",themeItems,false);
            size_t newBoardNdx = StringUtils::indexOf("imgNewBoard.png",themeItems,false);
            size_t exitNdx = StringUtils::indexOf("imgExit.png",themeItems,false);
            size_t backgroundNdx = StringUtils::indexOf("imgBackground.png",themeItems,false);
            size_t logoNdx = StringUtils::indexOf("imgLogo.png",themeItems,false);

            theme.setLogoUrl(FileUtils::buildFilePath(folder,themeItems[logoNdx]));
            theme.setBackgroundUrl(FileUtils::buildFilePath(folder,themeItems[backgroundNdx]));
            theme.setNewTaskButtonUrl(FileUtils::buildFilePath(folder,themeItems[newTaskNdx]));
            theme.setNewBoardButtonUrl(FileUtils::buildFilePath(folder,themeItems[newBoardNdx]));
            theme.setExitButtonUrl(FileUtils::buildFilePath(folder,themeItems[exitNdx]));
            theme.setName(FileUtils::getFileName(folder));
            themes.push_back(theme);

        }
        catch(std::exception & e)
        {
            continue;
        }
    }
    return themes;

}

size_t KanSoloProjectManager::getDefaultThemeIndex() const
{
    QueryBuilder qb;
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    qb["@table"]=tbBeg+"users"+tbEnd;
    qb["@name"]=idBeg+ "name"+idEnd;
    qb["@defBoard"]=idBeg+ "default_board"+idEnd;
    qb["@defTheme"]=idBeg+ "default_theme"+idEnd;
    qb["@user"]=litBeg+SystemUtils::getUserName()+litEnd;

    std::string query = "SELECT @defTheme FROM @table WHERE @name = @user;";
    query = qb.buildQuery(query);
    QueryResultPtr results = m_connection->query(query);
    qb.clean(idBeg);
    qb.clean(idEnd);
    qb.clean(litBeg);
    qb.clean(litEnd);
    if (results->isValid())
    {
        int count = results->getNumResultRows();
        for (size_t a1 = 0;a1 < count; ++a1)
        {
            ResultDataRow dataRow = results->getResultRow(a1);
            return dataRow.getInteger(qb["@defTheme"]);
        }
    }
    throw ThemeIndexNotFoundException();
}

size_t KanSoloProjectManager::getDefaultBoardIndex() const
{
    QueryBuilder qb;
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    qb["@table"]=tbBeg+"users"+tbEnd;
    qb["@name"]=idBeg+ "name"+idEnd;
    qb["@defBoard"]=idBeg+ "default_board"+idEnd;
    qb["@defTheme"]=idBeg+ "default_theme"+idEnd;
    qb["@user"]=litBeg+SystemUtils::getUserName()+litEnd;

    std::string query = "SELECT @defBoard FROM @table WHERE @name = @user;";
    query = qb.buildQuery(query);
    QueryResultPtr results = m_connection->query(query);
    qb.clean(idBeg);
    qb.clean(idEnd);
    qb.clean(litBeg);
    qb.clean(litEnd);
    if (results->isValid())
    {
        int count = results->getNumResultRows();
        for (size_t a1 = 0;a1 < count; ++a1)
        {
            ResultDataRow dataRow = results->getResultRow(a1);
            return dataRow.getInteger(qb["@defBoard"]);
        }
    }

    throw BoardIndexNotFoundException();
}

void KanSoloProjectManager::setDefaultBoardIndex(size_t index)
{
    QueryBuilder qb;
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    qb["@table"]=tbBeg+"users"+tbEnd;
    qb["@name"]=idBeg+ "name"+idEnd;
    qb["@defBoard"]=idBeg+ "default_board"+idEnd;
    qb["@defTheme"]=idBeg+ "default_theme"+idEnd;
    qb["@user"]=litBeg+SystemUtils::getUserName()+litEnd;
    qb["@index"]=StringUtils::toString(index);
    std::string query = "UPDATE @table SET @defBoard = @index WHERE @name = @user;";
    query = qb.buildQuery(query);
    m_connection->query(query);
}

void KanSoloProjectManager::setDefaultThemeIndex(size_t index)
{
    QueryBuilder qb;
    std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
    m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

    qb["@table"]=tbBeg+"users"+tbEnd;
    qb["@name"]=idBeg+ "name"+idEnd;
    qb["@defBoard"]=idBeg+ "default_board"+idEnd;
    qb["@defTheme"]=idBeg+ "default_theme"+idEnd;
    qb["@user"]=litBeg+SystemUtils::getUserName()+litEnd;
    qb["@index"]=StringUtils::toString(index);
    std::string query = "UPDATE @table SET @defTheme = @index WHERE @name = @user;";
    query = qb.buildQuery(query);
    m_connection->query(query);
}

void KanSoloProjectManager::openDatabase(const std::string &filePath, bool purge)
{
    if (purge)
    {
        FileUtils::deleteFile(filePath);
    }
    m_connection = DatabaseConnectionFactory::create("SQLITE",filePath);
    if (m_connection.get())
    {
        //Create tasks table
        QueryBuilder qb;
        std::string litBeg,litEnd,idBeg,idEnd,tbBeg,tbEnd;
        m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::IDENTIFIER,idBeg,idEnd);
        m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::TABLE,tbBeg,tbEnd);
        m_connection->getQueryEnclosureFormatStrings(QueryEnclosureFormatType::LITERAL,litBeg,litEnd);

        qb["@table"]=tbBeg+"tasks"+tbEnd;
        qb["@id"]=idBeg+ "id"+idEnd;
        qb["@boardId"]=idBeg+ "board_id"+idEnd;
        qb["@title"]=idBeg+ "title"+idEnd;
        qb["@desc"]=idBeg+ "description"+idEnd;
        qb["@score"]=idBeg+ "score"+idEnd;
        qb["@state"]=idBeg+ "state"+idEnd;
        qb["@size"]=idBeg+ "size"+idEnd;
        qb["@priority"]=idBeg+ "priority"+idEnd;
        qb["@creator"]=idBeg+ "creator"+idEnd;
        qb["@assignee"]=idBeg+ "assignee"+idEnd;
        qb["@createDate"]=idBeg+ "create_date"+idEnd;
        qb["@updateDate"]=idBeg+ "update_date"+idEnd;
        qb["@closeDate"]=idBeg+ "close_date"+idEnd;
        qb["@createTime"]=idBeg+ "create_time"+idEnd;
        qb["@updateTime"]=idBeg+ "update_time"+idEnd;
        qb["@closeTime"]=idBeg+ "close_time"+idEnd;
        qb["@scaleX"]=idBeg+ "scale_x"+idEnd;
        qb["@scaleY"]=idBeg+ "scale_y"+idEnd;

        std::string query="CREATE TABLE IF NOT EXISTS @table";
        query +="(@id TEXT,@boardId TEXT,@title TEXT,@desc TEXT,"
                "@score INTEGER,@state INTEGER,@size INTEGER,"
                "@priority INTEGER,@creator TEXT,@assignee TEXT,"
                "@createDate INTEGER,@updateDate INTEGER,"
                "@closeDate INTEGER, @createTime INTEGER,"
                "@updateTime, INTEGER, @closeTime INTEGER,"
                "@scaleX NUMERIC,@scaleY NUMERIC);";

        query = qb.buildQuery(query);
        m_connection->query(query);


        //Create boards table
        qb.clear();
        qb["@table"]=tbBeg+"boards"+tbEnd;
        qb["@id"]=idBeg+ "id"+idEnd;
        qb["@title"]=idBeg+ "title"+idEnd;
        qb["@backTitle"]=idBeg+ "backlog_title"+idEnd;
        qb["@procTitle"]=idBeg+ "processing_title"+idEnd;
        qb["@testTitle"]=idBeg+ "testing_title"+idEnd;
        qb["@finishedTitle"]=idBeg+ "finished_title"+idEnd;
        qb["@procCount"]=idBeg+ "processing_count"+idEnd;
        qb["@testCount"]=idBeg+ "testing_count"+idEnd;
        qb["@date"]=idBeg+ "board_creation_date"+idEnd;
        qb["@time"]=idBeg+ "board_creation_time"+idEnd;

        query ="CREATE TABLE IF NOT EXISTS ";
        query += "@table (@id TEXT,@title TEXT,@backTitle TEXT,"
                 "@procTitle TEXT,@testTitle TEXT,@finishedTitle TEXT,"
                 "@procCount INTEGER,@testCount INTEGER,"
                 "@date INTEGER, @time INTEGER);";

        query = qb.buildQuery(query);                
        m_connection->query(query);


        qb.clear();
        qb["@table"]=tbBeg+"users"+tbEnd;
        qb["@name"]=idBeg+ "name"+idEnd;
        qb["@defBoard"]=idBeg+ "default_board"+idEnd;
        qb["@defTheme"]=idBeg+ "default_theme"+idEnd;
        query ="CREATE TABLE IF NOT EXISTS ";
        query += "@table (@name TEXT,@defBoardIndex INTEGER,@defThemeIndex INTEGER);";
    }
}

KanSoloProjectManager::KanSoloProjectManager()
{

}

KanSoloProjectManager::~KanSoloProjectManager()
{

}





}}}//end namespace

