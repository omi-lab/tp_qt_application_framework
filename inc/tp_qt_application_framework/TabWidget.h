#ifndef tp_qt_application_framework_TabWidget_h
#define tp_qt_application_framework_TabWidget_h

#include "tp_qt_application_framework/Globals.h"

#include "json.hpp"

#include <QWidget>

namespace tp_qt_application_framework
{
class TP_QT_APPLICATION_FRAMEWORK_SHARED_EXPORT DisplayManager;

//##################################################################################################
//! Arranges displays in a splitter.
/*!
\ingroup DisplayContainers

This class allows the user to arrange displays in splitters. See \link DisplayContains Display
Containers \endlink for a list of classes that can be used for arranging displays.
*/
class TP_QT_APPLICATION_FRAMEWORK_SHARED_EXPORT TabWidget: public QWidget
{
  Q_OBJECT
  TP_DQ;
public:
  //################################################################################################
  //! Construct a split widget.
  /*!
  \param displayManager - The manager that will provide displays that can be added to the widget.
  \param parent - The parent widget.
  */
  TabWidget(DisplayManager* displayManager, QWidget* parent=nullptr);

  //################################################################################################
  //! Destructor
  /*!
  This will destroy the splitters and the child displays.
  */
  virtual ~TabWidget();

  //################################################################################################
  //! Save the state of this widget
  /*!
  Save the state of this TabWidget and all of its children.

  \returns The state of this widget as a serialized variant map.
  */
  void saveState(nlohmann::json& j) const;

  //################################################################################################
  //! Load the state of this widget
  /*!
  This will reset the widget deleting all children and then restore the state from the json,
  creating new splits and displays as required. This will also load the state of the newly created
  child displays.
  */
  void loadState(const nlohmann::json& j);

  //################################################################################################
  QWidget* configWidget();

public Q_SLOTS:
  //################################################################################################
  //! Set the visibility for splitter headers
  /*!
  Each splitter has a tool bar at the top that is used to configure the display, this method
  shows/hides that tool bar.

  \param visible - Sets the visibility of the tool bars.
  */
  void setToolBarsVisible(bool visible);

public:
  //################################################################################################
  //! Returns the visibility of the tool bars
  /*!
  \return Returns true if the tool bars are visible.
  \sa setToolBarsVisible()
  */
  bool toolBarsVisible() const;

private Q_SLOTS:
  //################################################################################################
  void configureTriggered();
};

}

#endif
