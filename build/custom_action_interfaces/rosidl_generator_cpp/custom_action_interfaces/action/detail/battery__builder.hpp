// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_action_interfaces:action/Battery.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_action_interfaces/action/battery.hpp"


#ifndef CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__BATTERY__BUILDER_HPP_
#define CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__BATTERY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_action_interfaces/action/detail/battery__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_Goal_cycles
{
public:
  Init_Battery_Goal_cycles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_action_interfaces::action::Battery_Goal cycles(::custom_action_interfaces::action::Battery_Goal::_cycles_type arg)
  {
    msg_.cycles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_Goal>()
{
  return custom_action_interfaces::action::builder::Init_Battery_Goal_cycles();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_Result_final_percentage
{
public:
  Init_Battery_Result_final_percentage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_action_interfaces::action::Battery_Result final_percentage(::custom_action_interfaces::action::Battery_Result::_final_percentage_type arg)
  {
    msg_.final_percentage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_Result>()
{
  return custom_action_interfaces::action::builder::Init_Battery_Result_final_percentage();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_Feedback_percentage_log
{
public:
  Init_Battery_Feedback_percentage_log()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_action_interfaces::action::Battery_Feedback percentage_log(::custom_action_interfaces::action::Battery_Feedback::_percentage_log_type arg)
  {
    msg_.percentage_log = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_Feedback>()
{
  return custom_action_interfaces::action::builder::Init_Battery_Feedback_percentage_log();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_SendGoal_Request_goal
{
public:
  explicit Init_Battery_SendGoal_Request_goal(::custom_action_interfaces::action::Battery_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Battery_SendGoal_Request goal(::custom_action_interfaces::action::Battery_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_SendGoal_Request msg_;
};

class Init_Battery_SendGoal_Request_goal_id
{
public:
  Init_Battery_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Battery_SendGoal_Request_goal goal_id(::custom_action_interfaces::action::Battery_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Battery_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_SendGoal_Request>()
{
  return custom_action_interfaces::action::builder::Init_Battery_SendGoal_Request_goal_id();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_SendGoal_Response_stamp
{
public:
  explicit Init_Battery_SendGoal_Response_stamp(::custom_action_interfaces::action::Battery_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Battery_SendGoal_Response stamp(::custom_action_interfaces::action::Battery_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_SendGoal_Response msg_;
};

class Init_Battery_SendGoal_Response_accepted
{
public:
  Init_Battery_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Battery_SendGoal_Response_stamp accepted(::custom_action_interfaces::action::Battery_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Battery_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_SendGoal_Response>()
{
  return custom_action_interfaces::action::builder::Init_Battery_SendGoal_Response_accepted();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_SendGoal_Event_response
{
public:
  explicit Init_Battery_SendGoal_Event_response(::custom_action_interfaces::action::Battery_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Battery_SendGoal_Event response(::custom_action_interfaces::action::Battery_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_SendGoal_Event msg_;
};

class Init_Battery_SendGoal_Event_request
{
public:
  explicit Init_Battery_SendGoal_Event_request(::custom_action_interfaces::action::Battery_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Battery_SendGoal_Event_response request(::custom_action_interfaces::action::Battery_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Battery_SendGoal_Event_response(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_SendGoal_Event msg_;
};

class Init_Battery_SendGoal_Event_info
{
public:
  Init_Battery_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Battery_SendGoal_Event_request info(::custom_action_interfaces::action::Battery_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Battery_SendGoal_Event_request(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_SendGoal_Event>()
{
  return custom_action_interfaces::action::builder::Init_Battery_SendGoal_Event_info();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_GetResult_Request_goal_id
{
public:
  Init_Battery_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_action_interfaces::action::Battery_GetResult_Request goal_id(::custom_action_interfaces::action::Battery_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_GetResult_Request>()
{
  return custom_action_interfaces::action::builder::Init_Battery_GetResult_Request_goal_id();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_GetResult_Response_result
{
public:
  explicit Init_Battery_GetResult_Response_result(::custom_action_interfaces::action::Battery_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Battery_GetResult_Response result(::custom_action_interfaces::action::Battery_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_GetResult_Response msg_;
};

class Init_Battery_GetResult_Response_status
{
public:
  Init_Battery_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Battery_GetResult_Response_result status(::custom_action_interfaces::action::Battery_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Battery_GetResult_Response_result(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_GetResult_Response>()
{
  return custom_action_interfaces::action::builder::Init_Battery_GetResult_Response_status();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_GetResult_Event_response
{
public:
  explicit Init_Battery_GetResult_Event_response(::custom_action_interfaces::action::Battery_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Battery_GetResult_Event response(::custom_action_interfaces::action::Battery_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_GetResult_Event msg_;
};

class Init_Battery_GetResult_Event_request
{
public:
  explicit Init_Battery_GetResult_Event_request(::custom_action_interfaces::action::Battery_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Battery_GetResult_Event_response request(::custom_action_interfaces::action::Battery_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Battery_GetResult_Event_response(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_GetResult_Event msg_;
};

class Init_Battery_GetResult_Event_info
{
public:
  Init_Battery_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Battery_GetResult_Event_request info(::custom_action_interfaces::action::Battery_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Battery_GetResult_Event_request(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_GetResult_Event>()
{
  return custom_action_interfaces::action::builder::Init_Battery_GetResult_Event_info();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Battery_FeedbackMessage_feedback
{
public:
  explicit Init_Battery_FeedbackMessage_feedback(::custom_action_interfaces::action::Battery_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Battery_FeedbackMessage feedback(::custom_action_interfaces::action::Battery_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_FeedbackMessage msg_;
};

class Init_Battery_FeedbackMessage_goal_id
{
public:
  Init_Battery_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Battery_FeedbackMessage_feedback goal_id(::custom_action_interfaces::action::Battery_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Battery_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_action_interfaces::action::Battery_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Battery_FeedbackMessage>()
{
  return custom_action_interfaces::action::builder::Init_Battery_FeedbackMessage_goal_id();
}

}  // namespace custom_action_interfaces

#endif  // CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__BATTERY__BUILDER_HPP_
