#ifndef tp_qt_application_framework_EventLatencyWidget_h
#define tp_qt_application_framework_EventLatencyWidget_h

#include "tp_qt_application_framework/Globals.h"

#include <QWidget>

namespace tp_qt_application_framework
{

//##################################################################################################
//! Displays the lock stats for TPMutex
class TP_QT_APPLICATION_FRAMEWORK_SHARED_EXPORT EventLatencyWidget: public QWidget
{
  Q_OBJECT
  TP_DQ;
public:
  //################################################################################################
  EventLatencyWidget(QWidget* parent=nullptr);

  //################################################################################################
  virtual ~EventLatencyWidget();
};

}

#endif
