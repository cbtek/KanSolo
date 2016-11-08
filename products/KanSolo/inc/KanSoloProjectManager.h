/**
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef _CBTEK_PRODUCTS_SOLO_SCRUM_PROJECTMANAGER_H
#define _CBTEK_PRODUCTS_SOLO_SCRUM_PROJECTMANAGER_H

#include <string>
#include <map>
#include <vector>

#include "KanSoloBoard.h"
#include "KanSoloProject.h"
#include "KanSoloTask.h"
#include "KanSoloTheme.h"

#include "database/inc/DatabaseConnectionFactory.h"

using namespace cbtek::common::database;

namespace cbtek {
namespace products {
namespace kan_solo {

enum class TaskCleanupStrategy
{
    DELETE_ASSOCIATED_TASKS,
    UNASSIGN_ASSOCIATED_TASKS,
    LEAVE_TASKS_ALONE
};

class KanSoloProjectManager
{

public:
    //! Constructor for KanSoloProjectManager
	/*!
        Detailed description for KanSoloProjectManager
	*/
    KanSoloProjectManager();

	//! Static instance method for this singleton
    static KanSoloProjectManager & inst();

    /**
     * @brief getActiveBoards     
     * @return
     */
    std::vector<KanSoloBoard> getBoards() const;

    /**
     * @brief getBacklogTasks     
     * @return
     */
    std::vector<KanSoloTask> getTasks(const std::string & boardId="") const;


    /**
     * @brief createTask     
     * @param task
     */
    void createTask(const KanSoloTask & task);

    /**
     * @brief removeTask     
     * @param taskId
     */
    void removeTask(const std::string & boardId,
                    const std::string & taskId);

    /**
     * @brief updateTask     
     * @param task
     */
    void updateTask(const std::string & boardId,
                    const KanSoloTask & task);


    /**
     * @brief createBoard
     * @param board
     */
    void createBoard(const KanSoloBoard & board);

    /**
     * @brief removeBoard     
     * @param boardId
     */
    void removeBoard(const std::string &boardId,TaskCleanupStrategy cleanupStrategy=TaskCleanupStrategy::LEAVE_TASKS_ALONE);

    /**
     * @brief updateBoard
     * @param board
     */
    void updateBoard(const KanSoloBoard & board);

    void openDatabase(const std::string & filePath, bool purge=false);

    std::vector<KanSoloTheme> getThemes() const;


    size_t getDefaultThemeIndex() const;

    size_t getDefaultBoardIndex() const;

    void setDefaultBoardIndex(size_t index);

    void setDefaultThemeIndex(size_t index);

    //! Destructor
    ~KanSoloProjectManager();

private:
    DatabaseConnectionPtr m_connection;
    static KanSoloProjectManager m_instance;



    
};
}}}//end namespace

#endif

