#ifndef tp_qt_application_framework_RefCountDisplayFactory_h
#define tp_qt_application_framework_RefCountDisplayFactory_h

#include "tp_qt_application_framework/AbstractDisplayFactory.h"

namespace tp_qt_application_framework
{

//##################################################################################################
//! Creates a display that shows a table of ref-counted objects.
/*!
Some objects use tp_qt_utils::RefCount class to keep a count of the number of instances of that 
object. This is mainly to keep track of memory usage, and to spot memory leaks. This class is used 
to add a display containing the table of reference counts.
*/
class TP_QT_APPLICATION_FRAMEWORK_SHARED_EXPORT RefCountDisplayFactory: public tp_qt_application_framework::AbstractDisplayFactory
{
public:
  //################################################################################################
  RefCountDisplayFactory();

  //################################################################################################
  ~RefCountDisplayFactory() override;

  //################################################################################################
  tp_qt_application_framework::AbstractDisplay* produceDisplay() override;
};

}

#endif
