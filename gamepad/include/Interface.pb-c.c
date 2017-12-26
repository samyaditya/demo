/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: Interface.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "Interface.pb-c.h"
void   axis__init
                     (Axis         *message)
{
  static Axis init_value = AXIS__INIT;
  *message = init_value;
}
size_t axis__get_packed_size
                     (const Axis *message)
{
  assert(message->base.descriptor == &axis__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t axis__pack
                     (const Axis *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &axis__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t axis__pack_to_buffer
                     (const Axis *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &axis__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Axis *
       axis__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Axis *)
     protobuf_c_message_unpack (&axis__descriptor,
                                allocator, len, data);
}
void   axis__free_unpacked
                     (Axis *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &axis__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   button__init
                     (Button         *message)
{
  static Button init_value = BUTTON__INIT;
  *message = init_value;
}
size_t button__get_packed_size
                     (const Button *message)
{
  assert(message->base.descriptor == &button__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t button__pack
                     (const Button *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &button__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t button__pack_to_buffer
                     (const Button *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &button__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Button *
       button__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Button *)
     protobuf_c_message_unpack (&button__descriptor,
                                allocator, len, data);
}
void   button__free_unpacked
                     (Button *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &button__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   game_pad__init
                     (GamePad         *message)
{
  static GamePad init_value = GAME_PAD__INIT;
  *message = init_value;
}
size_t game_pad__get_packed_size
                     (const GamePad *message)
{
  assert(message->base.descriptor == &game_pad__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t game_pad__pack
                     (const GamePad *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &game_pad__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t game_pad__pack_to_buffer
                     (const GamePad *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &game_pad__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
GamePad *
       game_pad__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (GamePad *)
     protobuf_c_message_unpack (&game_pad__descriptor,
                                allocator, len, data);
}
void   game_pad__free_unpacked
                     (GamePad *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &game_pad__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const MessageType axis__msg_type__default_value = MESSAGE_TYPE__MSG_AXIS;
static const ProtobufCFieldDescriptor axis__field_descriptors[3] =
{
  {
    "MsgType",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_ENUM,
    offsetof(Axis, has_msgtype),
    offsetof(Axis, msgtype),
    &message_type__descriptor,
    &axis__msg_type__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "X",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Axis, x),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "Y",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Axis, y),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned axis__field_indices_by_name[] = {
  0,   /* field[0] = MsgType */
  1,   /* field[1] = X */
  2,   /* field[2] = Y */
};
static const ProtobufCIntRange axis__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor axis__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Axis",
  "Axis",
  "Axis",
  "",
  sizeof(Axis),
  3,
  axis__field_descriptors,
  axis__field_indices_by_name,
  1,  axis__number_ranges,
  (ProtobufCMessageInit) axis__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const MessageType button__msg_type__default_value = MESSAGE_TYPE__MSG_BUTTON;
static const ProtobufCFieldDescriptor button__field_descriptors[2] =
{
  {
    "MsgType",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_ENUM,
    offsetof(Button, has_msgtype),
    offsetof(Button, msgtype),
    &message_type__descriptor,
    &button__msg_type__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "State",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BOOL,
    0,   /* quantifier_offset */
    offsetof(Button, state),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned button__field_indices_by_name[] = {
  0,   /* field[0] = MsgType */
  1,   /* field[1] = State */
};
static const ProtobufCIntRange button__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor button__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Button",
  "Button",
  "Button",
  "",
  sizeof(Button),
  2,
  button__field_descriptors,
  button__field_indices_by_name,
  1,  button__number_ranges,
  (ProtobufCMessageInit) button__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const MessageType game_pad__msg_type__default_value = MESSAGE_TYPE__MSG_GAMEPAD;
static const ProtobufCFieldDescriptor game_pad__field_descriptors[7] =
{
  {
    "MsgType",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_ENUM,
    offsetof(GamePad, has_msgtype),
    offsetof(GamePad, msgtype),
    &message_type__descriptor,
    &game_pad__msg_type__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "Stick1",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(GamePad, stick1),
    &axis__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "Stick2",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(GamePad, stick2),
    &axis__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "Triangle",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(GamePad, triangle),
    &button__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "O",
    5,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(GamePad, o),
    &button__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "X",
    6,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(GamePad, x),
    &button__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "Square",
    7,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(GamePad, square),
    &button__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned game_pad__field_indices_by_name[] = {
  0,   /* field[0] = MsgType */
  4,   /* field[4] = O */
  6,   /* field[6] = Square */
  1,   /* field[1] = Stick1 */
  2,   /* field[2] = Stick2 */
  3,   /* field[3] = Triangle */
  5,   /* field[5] = X */
};
static const ProtobufCIntRange game_pad__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 7 }
};
const ProtobufCMessageDescriptor game_pad__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "GamePad",
  "GamePad",
  "GamePad",
  "",
  sizeof(GamePad),
  7,
  game_pad__field_descriptors,
  game_pad__field_indices_by_name,
  1,  game_pad__number_ranges,
  (ProtobufCMessageInit) game_pad__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue message_type__enum_values_by_number[3] =
{
  { "MSG_AXIS", "MESSAGE_TYPE__MSG_AXIS", 1 },
  { "MSG_BUTTON", "MESSAGE_TYPE__MSG_BUTTON", 2 },
  { "MSG_GAMEPAD", "MESSAGE_TYPE__MSG_GAMEPAD", 4 },
};
static const ProtobufCIntRange message_type__value_ranges[] = {
{1, 0},{4, 2},{0, 3}
};
static const ProtobufCEnumValueIndex message_type__enum_values_by_name[3] =
{
  { "MSG_AXIS", 0 },
  { "MSG_BUTTON", 1 },
  { "MSG_GAMEPAD", 2 },
};
const ProtobufCEnumDescriptor message_type__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "MessageType",
  "MessageType",
  "MessageType",
  "",
  3,
  message_type__enum_values_by_number,
  3,
  message_type__enum_values_by_name,
  2,
  message_type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
