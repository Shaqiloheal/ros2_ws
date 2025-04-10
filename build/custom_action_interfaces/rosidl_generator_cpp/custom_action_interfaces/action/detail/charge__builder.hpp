// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_action_interfaces:action/Charge.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_action_interfaces/action/charge.hpp"


#ifndef CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__CHARGE__BUILDER_HPP_
#define CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__CHARGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_action_interfaces/action/detail/charge__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_Goal_target_percentage
{
public:
  Init_Charge_Goal_target_percentage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_action_interfaces::action::Charge_Goal target_percentage(::custom_action_interfaces::action::Charge_Goal::_target_percentage_type arg)
  {
    msg_.target_percentage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_Goal>()
{
  return custom_action_interfaces::action::builder::Init_Charge_Goal_target_percentage();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_Result_success
{
public:
  Init_Charge_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_action_interfaces::action::Charge_Result success(::custom_action_interfaces::action::Charge_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_Result>()
{
  return custom_action_interfaces::action::builder::Init_Charge_Result_success();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_Feedback_current_percentage
{
public:
  Init_Charge_Feedback_current_percentage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_action_interfaces::action::Charge_Feedback current_percentage(::custom_action_interfaces::action::Charge_Feedback::_current_percentage_type arg)
  {
    msg_.current_percentage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_Feedback>()
{
  return custom_action_interfaces::action::builder::Init_Charge_Feedback_current_percentage();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_SendGoal_Request_goal
{
public:
  explicit Init_Charge_SendGoal_Request_goal(::custom_action_interfaces::action::Charge_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Charge_SendGoal_Request goal(::custom_action_interfaces::action::Charge_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_SendGoal_Request msg_;
};

class Init_Charge_SendGoal_Request_goal_id
{
public:
  Init_Charge_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Charge_SendGoal_Request_goal goal_id(::custom_action_interfaces::action::Charge_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Charge_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_SendGoal_Request>()
{
  return custom_action_interfaces::action::builder::Init_Charge_SendGoal_Request_goal_id();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_SendGoal_Response_stamp
{
public:
  explicit Init_Charge_SendGoal_Response_stamp(::custom_action_interfaces::action::Charge_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Charge_SendGoal_Response stamp(::custom_action_interfaces::action::Charge_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_SendGoal_Response msg_;
};

class Init_Charge_SendGoal_Response_accepted
{
public:
  Init_Charge_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Charge_SendGoal_Response_stamp accepted(::custom_action_interfaces::action::Charge_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Charge_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_SendGoal_Response>()
{
  return custom_action_interfaces::action::builder::Init_Charge_SendGoal_Response_accepted();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_SendGoal_Event_response
{
public:
  explicit Init_Charge_SendGoal_Event_response(::custom_action_interfaces::action::Charge_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Charge_SendGoal_Event response(::custom_action_interfaces::action::Charge_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_SendGoal_Event msg_;
};

class Init_Charge_SendGoal_Event_request
{
public:
  explicit Init_Charge_SendGoal_Event_request(::custom_action_interfaces::action::Charge_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Charge_SendGoal_Event_response request(::custom_action_interfaces::action::Charge_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Charge_SendGoal_Event_response(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_SendGoal_Event msg_;
};

class Init_Charge_SendGoal_Event_info
{
public:
  Init_Charge_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Charge_SendGoal_Event_request info(::custom_action_interfaces::action::Charge_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Charge_SendGoal_Event_request(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_SendGoal_Event>()
{
  return custom_action_interfaces::action::builder::Init_Charge_SendGoal_Event_info();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_GetResult_Request_goal_id
{
public:
  Init_Charge_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_action_interfaces::action::Charge_GetResult_Request goal_id(::custom_action_interfaces::action::Charge_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_GetResult_Request>()
{
  return custom_action_interfaces::action::builder::Init_Charge_GetResult_Request_goal_id();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_GetResult_Response_result
{
public:
  explicit Init_Charge_GetResult_Response_result(::custom_action_interfaces::action::Charge_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Charge_GetResult_Response result(::custom_action_interfaces::action::Charge_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_GetResult_Response msg_;
};

class Init_Charge_GetResult_Response_status
{
public:
  Init_Charge_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Charge_GetResult_Response_result status(::custom_action_interfaces::action::Charge_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Charge_GetResult_Response_result(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_GetResult_Response>()
{
  return custom_action_interfaces::action::builder::Init_Charge_GetResult_Response_status();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_GetResult_Event_response
{
public:
  explicit Init_Charge_GetResult_Event_response(::custom_action_interfaces::action::Charge_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Charge_GetResult_Event response(::custom_action_interfaces::action::Charge_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_GetResult_Event msg_;
};

class Init_Charge_GetResult_Event_request
{
public:
  explicit Init_Charge_GetResult_Event_request(::custom_action_interfaces::action::Charge_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Charge_GetResult_Event_response request(::custom_action_interfaces::action::Charge_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Charge_GetResult_Event_response(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_GetResult_Event msg_;
};

class Init_Charge_GetResult_Event_info
{
public:
  Init_Charge_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Charge_GetResult_Event_request info(::custom_action_interfaces::action::Charge_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Charge_GetResult_Event_request(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_GetResult_Event>()
{
  return custom_action_interfaces::action::builder::Init_Charge_GetResult_Event_info();
}

}  // namespace custom_action_interfaces


namespace custom_action_interfaces
{

namespace action
{

namespace builder
{

class Init_Charge_FeedbackMessage_feedback
{
public:
  explicit Init_Charge_FeedbackMessage_feedback(::custom_action_interfaces::action::Charge_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_action_interfaces::action::Charge_FeedbackMessage feedback(::custom_action_interfaces::action::Charge_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_FeedbackMessage msg_;
};

class Init_Charge_FeedbackMessage_goal_id
{
public:
  Init_Charge_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Charge_FeedbackMessage_feedback goal_id(::custom_action_interfaces::action::Charge_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Charge_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_action_interfaces::action::Charge_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_action_interfaces::action::Charge_FeedbackMessage>()
{
  return custom_action_interfaces::action::builder::Init_Charge_FeedbackMessage_goal_id();
}

}  // namespace custom_action_interfaces

#endif  // CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__CHARGE__BUILDER_HPP_
