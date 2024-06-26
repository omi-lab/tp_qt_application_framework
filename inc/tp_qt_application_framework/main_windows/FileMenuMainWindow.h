#ifndef tp_qt_application_framework_FileMenuMainWindow_h
#define tp_qt_application_framework_FileMenuMainWindow_h

#include "tp_qt_application_framework/AbstractMainWindow.h"

namespace tp_qt_application_framework
{
class AbstractWorkspace;

//##################################################################################################
class TP_QT_APPLICATION_FRAMEWORK_SHARED_EXPORT FileMenuMainWindow: public AbstractMainWindow
{
  Q_OBJECT
  TP_DQ;
public:
  //################################################################################################
  FileMenuMainWindow(QWidget* parent=nullptr);

  //################################################################################################
  ~FileMenuMainWindow() override;

  //################################################################################################
  //! This will add a workspace to this main window
  /*!
  \note This will take ownership of the workspace.
  \param workspace - The new workspace to add.
  */
  void addWorkspace(AbstractWorkspace* workspace) override;

  //################################################################################################
  //! Add a menu to the menu bar
  /*!
  This will take ownership of the menu and will delete it in the destructor not before.

  \param menu - The nenu to add to the menu bar.
  */
  void addMenu(QMenu* menu) override;

protected:
  //################################################################################################
  //! Called when the current workspace changes
  void currentWorkspaceChanged() override;
};

}

#endif
