// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_action_interfaces:action/Battery.idl
// generated code does not contain a copyright notice
#include "custom_action_interfaces/action/detail/battery__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_action_interfaces__action__Battery_Goal__init(custom_action_interfaces__action__Battery_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // cycles
  return true;
}

void
custom_action_interfaces__action__Battery_Goal__fini(custom_action_interfaces__action__Battery_Goal * msg)
{
  if (!msg) {
    return;
  }
  // cycles
}

bool
custom_action_interfaces__action__Battery_Goal__are_equal(const custom_action_interfaces__action__Battery_Goal * lhs, const custom_action_interfaces__action__Battery_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cycles
  if (lhs->cycles != rhs->cycles) {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_Goal__copy(
  const custom_action_interfaces__action__Battery_Goal * input,
  custom_action_interfaces__action__Battery_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // cycles
  output->cycles = input->cycles;
  return true;
}

custom_action_interfaces__action__Battery_Goal *
custom_action_interfaces__action__Battery_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Goal * msg = (custom_action_interfaces__action__Battery_Goal *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_Goal));
  bool success = custom_action_interfaces__action__Battery_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_Goal__destroy(custom_action_interfaces__action__Battery_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_Goal__Sequence__init(custom_action_interfaces__action__Battery_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Goal * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_Goal *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_Goal__Sequence__fini(custom_action_interfaces__action__Battery_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_Goal__Sequence *
custom_action_interfaces__action__Battery_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Goal__Sequence * array = (custom_action_interfaces__action__Battery_Goal__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_Goal__Sequence__destroy(custom_action_interfaces__action__Battery_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_Goal__Sequence__are_equal(const custom_action_interfaces__action__Battery_Goal__Sequence * lhs, const custom_action_interfaces__action__Battery_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_Goal__Sequence__copy(
  const custom_action_interfaces__action__Battery_Goal__Sequence * input,
  custom_action_interfaces__action__Battery_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_Goal * data =
      (custom_action_interfaces__action__Battery_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `final_percentage`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custom_action_interfaces__action__Battery_Result__init(custom_action_interfaces__action__Battery_Result * msg)
{
  if (!msg) {
    return false;
  }
  // final_percentage
  if (!rosidl_runtime_c__float__Sequence__init(&msg->final_percentage, 0)) {
    custom_action_interfaces__action__Battery_Result__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_Result__fini(custom_action_interfaces__action__Battery_Result * msg)
{
  if (!msg) {
    return;
  }
  // final_percentage
  rosidl_runtime_c__float__Sequence__fini(&msg->final_percentage);
}

bool
custom_action_interfaces__action__Battery_Result__are_equal(const custom_action_interfaces__action__Battery_Result * lhs, const custom_action_interfaces__action__Battery_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // final_percentage
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->final_percentage), &(rhs->final_percentage)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_Result__copy(
  const custom_action_interfaces__action__Battery_Result * input,
  custom_action_interfaces__action__Battery_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // final_percentage
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->final_percentage), &(output->final_percentage)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_Result *
custom_action_interfaces__action__Battery_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Result * msg = (custom_action_interfaces__action__Battery_Result *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_Result));
  bool success = custom_action_interfaces__action__Battery_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_Result__destroy(custom_action_interfaces__action__Battery_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_Result__Sequence__init(custom_action_interfaces__action__Battery_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Result * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_Result *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_Result__Sequence__fini(custom_action_interfaces__action__Battery_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_Result__Sequence *
custom_action_interfaces__action__Battery_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Result__Sequence * array = (custom_action_interfaces__action__Battery_Result__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_Result__Sequence__destroy(custom_action_interfaces__action__Battery_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_Result__Sequence__are_equal(const custom_action_interfaces__action__Battery_Result__Sequence * lhs, const custom_action_interfaces__action__Battery_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_Result__Sequence__copy(
  const custom_action_interfaces__action__Battery_Result__Sequence * input,
  custom_action_interfaces__action__Battery_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_Result * data =
      (custom_action_interfaces__action__Battery_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `percentage_log`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custom_action_interfaces__action__Battery_Feedback__init(custom_action_interfaces__action__Battery_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // percentage_log
  if (!rosidl_runtime_c__float__Sequence__init(&msg->percentage_log, 0)) {
    custom_action_interfaces__action__Battery_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_Feedback__fini(custom_action_interfaces__action__Battery_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // percentage_log
  rosidl_runtime_c__float__Sequence__fini(&msg->percentage_log);
}

bool
custom_action_interfaces__action__Battery_Feedback__are_equal(const custom_action_interfaces__action__Battery_Feedback * lhs, const custom_action_interfaces__action__Battery_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // percentage_log
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->percentage_log), &(rhs->percentage_log)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_Feedback__copy(
  const custom_action_interfaces__action__Battery_Feedback * input,
  custom_action_interfaces__action__Battery_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // percentage_log
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->percentage_log), &(output->percentage_log)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_Feedback *
custom_action_interfaces__action__Battery_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Feedback * msg = (custom_action_interfaces__action__Battery_Feedback *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_Feedback));
  bool success = custom_action_interfaces__action__Battery_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_Feedback__destroy(custom_action_interfaces__action__Battery_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_Feedback__Sequence__init(custom_action_interfaces__action__Battery_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Feedback * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_Feedback *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_Feedback__Sequence__fini(custom_action_interfaces__action__Battery_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_Feedback__Sequence *
custom_action_interfaces__action__Battery_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_Feedback__Sequence * array = (custom_action_interfaces__action__Battery_Feedback__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_Feedback__Sequence__destroy(custom_action_interfaces__action__Battery_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_Feedback__Sequence__are_equal(const custom_action_interfaces__action__Battery_Feedback__Sequence * lhs, const custom_action_interfaces__action__Battery_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_Feedback__Sequence__copy(
  const custom_action_interfaces__action__Battery_Feedback__Sequence * input,
  custom_action_interfaces__action__Battery_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_Feedback * data =
      (custom_action_interfaces__action__Battery_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "custom_action_interfaces/action/detail/battery__functions.h"

bool
custom_action_interfaces__action__Battery_SendGoal_Request__init(custom_action_interfaces__action__Battery_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    custom_action_interfaces__action__Battery_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!custom_action_interfaces__action__Battery_Goal__init(&msg->goal)) {
    custom_action_interfaces__action__Battery_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_SendGoal_Request__fini(custom_action_interfaces__action__Battery_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  custom_action_interfaces__action__Battery_Goal__fini(&msg->goal);
}

bool
custom_action_interfaces__action__Battery_SendGoal_Request__are_equal(const custom_action_interfaces__action__Battery_SendGoal_Request * lhs, const custom_action_interfaces__action__Battery_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!custom_action_interfaces__action__Battery_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_SendGoal_Request__copy(
  const custom_action_interfaces__action__Battery_SendGoal_Request * input,
  custom_action_interfaces__action__Battery_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!custom_action_interfaces__action__Battery_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_SendGoal_Request *
custom_action_interfaces__action__Battery_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Request * msg = (custom_action_interfaces__action__Battery_SendGoal_Request *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_SendGoal_Request));
  bool success = custom_action_interfaces__action__Battery_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_SendGoal_Request__destroy(custom_action_interfaces__action__Battery_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__init(custom_action_interfaces__action__Battery_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Request * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_SendGoal_Request *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__fini(custom_action_interfaces__action__Battery_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_SendGoal_Request__Sequence *
custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Request__Sequence * array = (custom_action_interfaces__action__Battery_SendGoal_Request__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__destroy(custom_action_interfaces__action__Battery_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__are_equal(const custom_action_interfaces__action__Battery_SendGoal_Request__Sequence * lhs, const custom_action_interfaces__action__Battery_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__copy(
  const custom_action_interfaces__action__Battery_SendGoal_Request__Sequence * input,
  custom_action_interfaces__action__Battery_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_SendGoal_Request * data =
      (custom_action_interfaces__action__Battery_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
custom_action_interfaces__action__Battery_SendGoal_Response__init(custom_action_interfaces__action__Battery_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    custom_action_interfaces__action__Battery_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_SendGoal_Response__fini(custom_action_interfaces__action__Battery_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
custom_action_interfaces__action__Battery_SendGoal_Response__are_equal(const custom_action_interfaces__action__Battery_SendGoal_Response * lhs, const custom_action_interfaces__action__Battery_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_SendGoal_Response__copy(
  const custom_action_interfaces__action__Battery_SendGoal_Response * input,
  custom_action_interfaces__action__Battery_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_SendGoal_Response *
custom_action_interfaces__action__Battery_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Response * msg = (custom_action_interfaces__action__Battery_SendGoal_Response *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_SendGoal_Response));
  bool success = custom_action_interfaces__action__Battery_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_SendGoal_Response__destroy(custom_action_interfaces__action__Battery_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__init(custom_action_interfaces__action__Battery_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Response * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_SendGoal_Response *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__fini(custom_action_interfaces__action__Battery_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_SendGoal_Response__Sequence *
custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Response__Sequence * array = (custom_action_interfaces__action__Battery_SendGoal_Response__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__destroy(custom_action_interfaces__action__Battery_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__are_equal(const custom_action_interfaces__action__Battery_SendGoal_Response__Sequence * lhs, const custom_action_interfaces__action__Battery_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__copy(
  const custom_action_interfaces__action__Battery_SendGoal_Response__Sequence * input,
  custom_action_interfaces__action__Battery_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_SendGoal_Response * data =
      (custom_action_interfaces__action__Battery_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "custom_action_interfaces/action/detail/battery__functions.h"

bool
custom_action_interfaces__action__Battery_SendGoal_Event__init(custom_action_interfaces__action__Battery_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    custom_action_interfaces__action__Battery_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    custom_action_interfaces__action__Battery_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    custom_action_interfaces__action__Battery_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_SendGoal_Event__fini(custom_action_interfaces__action__Battery_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
custom_action_interfaces__action__Battery_SendGoal_Event__are_equal(const custom_action_interfaces__action__Battery_SendGoal_Event * lhs, const custom_action_interfaces__action__Battery_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_SendGoal_Event__copy(
  const custom_action_interfaces__action__Battery_SendGoal_Event * input,
  custom_action_interfaces__action__Battery_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!custom_action_interfaces__action__Battery_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!custom_action_interfaces__action__Battery_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_SendGoal_Event *
custom_action_interfaces__action__Battery_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Event * msg = (custom_action_interfaces__action__Battery_SendGoal_Event *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_SendGoal_Event));
  bool success = custom_action_interfaces__action__Battery_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_SendGoal_Event__destroy(custom_action_interfaces__action__Battery_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_SendGoal_Event__Sequence__init(custom_action_interfaces__action__Battery_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Event * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_SendGoal_Event *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_SendGoal_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_SendGoal_Event__Sequence__fini(custom_action_interfaces__action__Battery_SendGoal_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_SendGoal_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_SendGoal_Event__Sequence *
custom_action_interfaces__action__Battery_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_SendGoal_Event__Sequence * array = (custom_action_interfaces__action__Battery_SendGoal_Event__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_SendGoal_Event__Sequence__destroy(custom_action_interfaces__action__Battery_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_SendGoal_Event__Sequence__are_equal(const custom_action_interfaces__action__Battery_SendGoal_Event__Sequence * lhs, const custom_action_interfaces__action__Battery_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_SendGoal_Event__Sequence__copy(
  const custom_action_interfaces__action__Battery_SendGoal_Event__Sequence * input,
  custom_action_interfaces__action__Battery_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_SendGoal_Event * data =
      (custom_action_interfaces__action__Battery_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
custom_action_interfaces__action__Battery_GetResult_Request__init(custom_action_interfaces__action__Battery_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    custom_action_interfaces__action__Battery_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_GetResult_Request__fini(custom_action_interfaces__action__Battery_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
custom_action_interfaces__action__Battery_GetResult_Request__are_equal(const custom_action_interfaces__action__Battery_GetResult_Request * lhs, const custom_action_interfaces__action__Battery_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_GetResult_Request__copy(
  const custom_action_interfaces__action__Battery_GetResult_Request * input,
  custom_action_interfaces__action__Battery_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_GetResult_Request *
custom_action_interfaces__action__Battery_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Request * msg = (custom_action_interfaces__action__Battery_GetResult_Request *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_GetResult_Request));
  bool success = custom_action_interfaces__action__Battery_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_GetResult_Request__destroy(custom_action_interfaces__action__Battery_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_GetResult_Request__Sequence__init(custom_action_interfaces__action__Battery_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Request * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_GetResult_Request *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_GetResult_Request__Sequence__fini(custom_action_interfaces__action__Battery_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_GetResult_Request__Sequence *
custom_action_interfaces__action__Battery_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Request__Sequence * array = (custom_action_interfaces__action__Battery_GetResult_Request__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_GetResult_Request__Sequence__destroy(custom_action_interfaces__action__Battery_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_GetResult_Request__Sequence__are_equal(const custom_action_interfaces__action__Battery_GetResult_Request__Sequence * lhs, const custom_action_interfaces__action__Battery_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_GetResult_Request__Sequence__copy(
  const custom_action_interfaces__action__Battery_GetResult_Request__Sequence * input,
  custom_action_interfaces__action__Battery_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_GetResult_Request * data =
      (custom_action_interfaces__action__Battery_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "custom_action_interfaces/action/detail/battery__functions.h"

bool
custom_action_interfaces__action__Battery_GetResult_Response__init(custom_action_interfaces__action__Battery_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!custom_action_interfaces__action__Battery_Result__init(&msg->result)) {
    custom_action_interfaces__action__Battery_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_GetResult_Response__fini(custom_action_interfaces__action__Battery_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  custom_action_interfaces__action__Battery_Result__fini(&msg->result);
}

bool
custom_action_interfaces__action__Battery_GetResult_Response__are_equal(const custom_action_interfaces__action__Battery_GetResult_Response * lhs, const custom_action_interfaces__action__Battery_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!custom_action_interfaces__action__Battery_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_GetResult_Response__copy(
  const custom_action_interfaces__action__Battery_GetResult_Response * input,
  custom_action_interfaces__action__Battery_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!custom_action_interfaces__action__Battery_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_GetResult_Response *
custom_action_interfaces__action__Battery_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Response * msg = (custom_action_interfaces__action__Battery_GetResult_Response *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_GetResult_Response));
  bool success = custom_action_interfaces__action__Battery_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_GetResult_Response__destroy(custom_action_interfaces__action__Battery_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_GetResult_Response__Sequence__init(custom_action_interfaces__action__Battery_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Response * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_GetResult_Response *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_GetResult_Response__Sequence__fini(custom_action_interfaces__action__Battery_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_GetResult_Response__Sequence *
custom_action_interfaces__action__Battery_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Response__Sequence * array = (custom_action_interfaces__action__Battery_GetResult_Response__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_GetResult_Response__Sequence__destroy(custom_action_interfaces__action__Battery_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_GetResult_Response__Sequence__are_equal(const custom_action_interfaces__action__Battery_GetResult_Response__Sequence * lhs, const custom_action_interfaces__action__Battery_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_GetResult_Response__Sequence__copy(
  const custom_action_interfaces__action__Battery_GetResult_Response__Sequence * input,
  custom_action_interfaces__action__Battery_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_GetResult_Response * data =
      (custom_action_interfaces__action__Battery_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "custom_action_interfaces/action/detail/battery__functions.h"

bool
custom_action_interfaces__action__Battery_GetResult_Event__init(custom_action_interfaces__action__Battery_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    custom_action_interfaces__action__Battery_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!custom_action_interfaces__action__Battery_GetResult_Request__Sequence__init(&msg->request, 0)) {
    custom_action_interfaces__action__Battery_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!custom_action_interfaces__action__Battery_GetResult_Response__Sequence__init(&msg->response, 0)) {
    custom_action_interfaces__action__Battery_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_GetResult_Event__fini(custom_action_interfaces__action__Battery_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  custom_action_interfaces__action__Battery_GetResult_Request__Sequence__fini(&msg->request);
  // response
  custom_action_interfaces__action__Battery_GetResult_Response__Sequence__fini(&msg->response);
}

bool
custom_action_interfaces__action__Battery_GetResult_Event__are_equal(const custom_action_interfaces__action__Battery_GetResult_Event * lhs, const custom_action_interfaces__action__Battery_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!custom_action_interfaces__action__Battery_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!custom_action_interfaces__action__Battery_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_GetResult_Event__copy(
  const custom_action_interfaces__action__Battery_GetResult_Event * input,
  custom_action_interfaces__action__Battery_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!custom_action_interfaces__action__Battery_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!custom_action_interfaces__action__Battery_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_GetResult_Event *
custom_action_interfaces__action__Battery_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Event * msg = (custom_action_interfaces__action__Battery_GetResult_Event *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_GetResult_Event));
  bool success = custom_action_interfaces__action__Battery_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_GetResult_Event__destroy(custom_action_interfaces__action__Battery_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_GetResult_Event__Sequence__init(custom_action_interfaces__action__Battery_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Event * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_GetResult_Event *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_GetResult_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_GetResult_Event__Sequence__fini(custom_action_interfaces__action__Battery_GetResult_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_GetResult_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_GetResult_Event__Sequence *
custom_action_interfaces__action__Battery_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_GetResult_Event__Sequence * array = (custom_action_interfaces__action__Battery_GetResult_Event__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_GetResult_Event__Sequence__destroy(custom_action_interfaces__action__Battery_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_GetResult_Event__Sequence__are_equal(const custom_action_interfaces__action__Battery_GetResult_Event__Sequence * lhs, const custom_action_interfaces__action__Battery_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_GetResult_Event__Sequence__copy(
  const custom_action_interfaces__action__Battery_GetResult_Event__Sequence * input,
  custom_action_interfaces__action__Battery_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_GetResult_Event * data =
      (custom_action_interfaces__action__Battery_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "custom_action_interfaces/action/detail/battery__functions.h"

bool
custom_action_interfaces__action__Battery_FeedbackMessage__init(custom_action_interfaces__action__Battery_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    custom_action_interfaces__action__Battery_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!custom_action_interfaces__action__Battery_Feedback__init(&msg->feedback)) {
    custom_action_interfaces__action__Battery_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
custom_action_interfaces__action__Battery_FeedbackMessage__fini(custom_action_interfaces__action__Battery_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  custom_action_interfaces__action__Battery_Feedback__fini(&msg->feedback);
}

bool
custom_action_interfaces__action__Battery_FeedbackMessage__are_equal(const custom_action_interfaces__action__Battery_FeedbackMessage * lhs, const custom_action_interfaces__action__Battery_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!custom_action_interfaces__action__Battery_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_FeedbackMessage__copy(
  const custom_action_interfaces__action__Battery_FeedbackMessage * input,
  custom_action_interfaces__action__Battery_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!custom_action_interfaces__action__Battery_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

custom_action_interfaces__action__Battery_FeedbackMessage *
custom_action_interfaces__action__Battery_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_FeedbackMessage * msg = (custom_action_interfaces__action__Battery_FeedbackMessage *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_action_interfaces__action__Battery_FeedbackMessage));
  bool success = custom_action_interfaces__action__Battery_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_action_interfaces__action__Battery_FeedbackMessage__destroy(custom_action_interfaces__action__Battery_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_action_interfaces__action__Battery_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_action_interfaces__action__Battery_FeedbackMessage__Sequence__init(custom_action_interfaces__action__Battery_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_FeedbackMessage * data = NULL;

  if (size) {
    data = (custom_action_interfaces__action__Battery_FeedbackMessage *)allocator.zero_allocate(size, sizeof(custom_action_interfaces__action__Battery_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_action_interfaces__action__Battery_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_action_interfaces__action__Battery_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_action_interfaces__action__Battery_FeedbackMessage__Sequence__fini(custom_action_interfaces__action__Battery_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_action_interfaces__action__Battery_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_action_interfaces__action__Battery_FeedbackMessage__Sequence *
custom_action_interfaces__action__Battery_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_action_interfaces__action__Battery_FeedbackMessage__Sequence * array = (custom_action_interfaces__action__Battery_FeedbackMessage__Sequence *)allocator.allocate(sizeof(custom_action_interfaces__action__Battery_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_action_interfaces__action__Battery_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_action_interfaces__action__Battery_FeedbackMessage__Sequence__destroy(custom_action_interfaces__action__Battery_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_action_interfaces__action__Battery_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_action_interfaces__action__Battery_FeedbackMessage__Sequence__are_equal(const custom_action_interfaces__action__Battery_FeedbackMessage__Sequence * lhs, const custom_action_interfaces__action__Battery_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_action_interfaces__action__Battery_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_action_interfaces__action__Battery_FeedbackMessage__Sequence__copy(
  const custom_action_interfaces__action__Battery_FeedbackMessage__Sequence * input,
  custom_action_interfaces__action__Battery_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_action_interfaces__action__Battery_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_action_interfaces__action__Battery_FeedbackMessage * data =
      (custom_action_interfaces__action__Battery_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_action_interfaces__action__Battery_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_action_interfaces__action__Battery_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_action_interfaces__action__Battery_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
