// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_action_interfaces:action/Battery.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_action_interfaces/action/battery.h"


#ifndef CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__BATTERY__STRUCT_H_
#define CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__BATTERY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_Goal
{
  int32_t cycles;
} custom_action_interfaces__action__Battery_Goal;

// Struct for a sequence of custom_action_interfaces__action__Battery_Goal.
typedef struct custom_action_interfaces__action__Battery_Goal__Sequence
{
  custom_action_interfaces__action__Battery_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'final_percentage'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_Result
{
  rosidl_runtime_c__float__Sequence final_percentage;
} custom_action_interfaces__action__Battery_Result;

// Struct for a sequence of custom_action_interfaces__action__Battery_Result.
typedef struct custom_action_interfaces__action__Battery_Result__Sequence
{
  custom_action_interfaces__action__Battery_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'percentage_log'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_Feedback
{
  rosidl_runtime_c__float__Sequence percentage_log;
} custom_action_interfaces__action__Battery_Feedback;

// Struct for a sequence of custom_action_interfaces__action__Battery_Feedback.
typedef struct custom_action_interfaces__action__Battery_Feedback__Sequence
{
  custom_action_interfaces__action__Battery_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "custom_action_interfaces/action/detail/battery__struct.h"

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_action_interfaces__action__Battery_Goal goal;
} custom_action_interfaces__action__Battery_SendGoal_Request;

// Struct for a sequence of custom_action_interfaces__action__Battery_SendGoal_Request.
typedef struct custom_action_interfaces__action__Battery_SendGoal_Request__Sequence
{
  custom_action_interfaces__action__Battery_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} custom_action_interfaces__action__Battery_SendGoal_Response;

// Struct for a sequence of custom_action_interfaces__action__Battery_SendGoal_Response.
typedef struct custom_action_interfaces__action__Battery_SendGoal_Response__Sequence
{
  custom_action_interfaces__action__Battery_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_action_interfaces__action__Battery_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_action_interfaces__action__Battery_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_action_interfaces__action__Battery_SendGoal_Request__Sequence request;
  custom_action_interfaces__action__Battery_SendGoal_Response__Sequence response;
} custom_action_interfaces__action__Battery_SendGoal_Event;

// Struct for a sequence of custom_action_interfaces__action__Battery_SendGoal_Event.
typedef struct custom_action_interfaces__action__Battery_SendGoal_Event__Sequence
{
  custom_action_interfaces__action__Battery_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} custom_action_interfaces__action__Battery_GetResult_Request;

// Struct for a sequence of custom_action_interfaces__action__Battery_GetResult_Request.
typedef struct custom_action_interfaces__action__Battery_GetResult_Request__Sequence
{
  custom_action_interfaces__action__Battery_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_action_interfaces/action/detail/battery__struct.h"

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_GetResult_Response
{
  int8_t status;
  custom_action_interfaces__action__Battery_Result result;
} custom_action_interfaces__action__Battery_GetResult_Response;

// Struct for a sequence of custom_action_interfaces__action__Battery_GetResult_Response.
typedef struct custom_action_interfaces__action__Battery_GetResult_Response__Sequence
{
  custom_action_interfaces__action__Battery_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_action_interfaces__action__Battery_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_action_interfaces__action__Battery_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_action_interfaces__action__Battery_GetResult_Request__Sequence request;
  custom_action_interfaces__action__Battery_GetResult_Response__Sequence response;
} custom_action_interfaces__action__Battery_GetResult_Event;

// Struct for a sequence of custom_action_interfaces__action__Battery_GetResult_Event.
typedef struct custom_action_interfaces__action__Battery_GetResult_Event__Sequence
{
  custom_action_interfaces__action__Battery_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "custom_action_interfaces/action/detail/battery__struct.h"

/// Struct defined in action/Battery in the package custom_action_interfaces.
typedef struct custom_action_interfaces__action__Battery_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_action_interfaces__action__Battery_Feedback feedback;
} custom_action_interfaces__action__Battery_FeedbackMessage;

// Struct for a sequence of custom_action_interfaces__action__Battery_FeedbackMessage.
typedef struct custom_action_interfaces__action__Battery_FeedbackMessage__Sequence
{
  custom_action_interfaces__action__Battery_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_action_interfaces__action__Battery_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_ACTION_INTERFACES__ACTION__DETAIL__BATTERY__STRUCT_H_
