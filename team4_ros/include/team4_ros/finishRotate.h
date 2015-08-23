// Generated by gencpp from file team4_ros/finishRotate.msg
// DO NOT EDIT!


#ifndef TEAM4_ROS_MESSAGE_FINISHROTATE_H
#define TEAM4_ROS_MESSAGE_FINISHROTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace team4_ros
{
template <class ContainerAllocator>
struct finishRotate_
{
  typedef finishRotate_<ContainerAllocator> Type;

  finishRotate_()
    : isFull(false)
    , x(0.0)
    , y(0.0)  {
    }
  finishRotate_(const ContainerAllocator& _alloc)
    : isFull(false)
    , x(0.0)
    , y(0.0)  {
    }



   typedef uint8_t _isFull_type;
  _isFull_type isFull;

   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;




  typedef boost::shared_ptr< ::team4_ros::finishRotate_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::team4_ros::finishRotate_<ContainerAllocator> const> ConstPtr;

}; // struct finishRotate_

typedef ::team4_ros::finishRotate_<std::allocator<void> > finishRotate;

typedef boost::shared_ptr< ::team4_ros::finishRotate > finishRotatePtr;
typedef boost::shared_ptr< ::team4_ros::finishRotate const> finishRotateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::team4_ros::finishRotate_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::team4_ros::finishRotate_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace team4_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'team4_ros': ['/home/parallels/catkin_ws/src/se306-1/team4_ros/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::team4_ros::finishRotate_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::team4_ros::finishRotate_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::team4_ros::finishRotate_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::team4_ros::finishRotate_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::team4_ros::finishRotate_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::team4_ros::finishRotate_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::team4_ros::finishRotate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "58615b89c8be04cc66454f6bad7cc4b9";
  }

  static const char* value(const ::team4_ros::finishRotate_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x58615b89c8be04ccULL;
  static const uint64_t static_value2 = 0x66454f6bad7cc4b9ULL;
};

template<class ContainerAllocator>
struct DataType< ::team4_ros::finishRotate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "team4_ros/finishRotate";
  }

  static const char* value(const ::team4_ros::finishRotate_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::team4_ros::finishRotate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool isFull \n\
float32 x\n\
float32 y\n\
";
  }

  static const char* value(const ::team4_ros::finishRotate_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::team4_ros::finishRotate_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.isFull);
      stream.next(m.x);
      stream.next(m.y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct finishRotate_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::team4_ros::finishRotate_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::team4_ros::finishRotate_<ContainerAllocator>& v)
  {
    s << indent << "isFull: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.isFull);
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEAM4_ROS_MESSAGE_FINISHROTATE_H
