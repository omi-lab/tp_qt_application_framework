#ifndef tp_qt_application_framework_AbstractMainWindow_h
#define tp_qt_application_framework_AbstractMainWindow_h

#include "tp_qt_application_framework/Globals.h"

#include "json.hpp"

#include <QList>
#include <QWidget>
#include <QMenu>

namespace tp_qt_application_framework
{
class AbstractWorkspace;

//##################################################################################################
class TP_QT_APPLICATION_FRAMEWORK_SHARED_EXPORT AbstractMainWindow: public QWidget
{
  Q_OBJECT
  TP_DQ;
public:
  //################################################################################################
  AbstractMainWindow(QWidget* parent=nullptr);

  //################################################################################################
  ~AbstractMainWindow();

  //################################################################################################
  void setQuestionExit(bool questionExit);

  //################################################################################################
  //! This will add a workspace to this main window
  /*!
  \note This will take ownership of the workspace.
  \param workspace - The new workspace to add.
  */
  virtual void addWorkspace(AbstractWorkspace* workspace);

  //################################################################################################
  virtual void setCurrentWorkspace(AbstractWorkspace* workspace);

  //################################################################################################
  //! Returns the list of workspaces in the order that they were added
  const std::vector<AbstractWorkspace*>& workspaces() const;

  //################################################################################################
  //! Returns the currently visible workspace
  AbstractWorkspace* currentWorkspace() const;

  //################################################################################################
  //! Add a menu to the menu bar
  /*!
  This will take ownership of the menu and will delete it in the destructor not before.

  \param menu - The nenu to add to the menu bar.
  */
  virtual void addMenu(QMenu* menu);

  //################################################################################################
  virtual void saveState(nlohmann::json& j) const;

  //################################################################################################
  virtual void loadState(const nlohmann::json& j);

protected:
  //################################################################################################
  //! Called when the current workspace changes
  virtual void currentWorkspaceChanged();

  //################################################################################################
  void closeEvent(QCloseEvent* closeEvent) override;
};

}

#endif
