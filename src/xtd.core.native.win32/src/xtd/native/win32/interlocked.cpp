#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/interlocked.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace std;
using namespace xtd::native;

int32_t interlocked::add(int32_t& location, int32_t value) {
  InterlockedExchange((long*)&location, location + value);
  return location;
}

int64_t interlocked::add(int64_t& location, int64_t value) {
  InterlockedExchange64((long long*)&location, location + value);
  return location;
}

int32_t interlocked::compare_exchange(int32_t& location, int32_t value, int32_t comparand) {
  return InterlockedCompareExchange((long*)&location, value, comparand);
}

int64_t interlocked::compare_exchange(int64_t& location, int64_t value, int64_t comparand) {
  return InterlockedCompareExchange64((long long*)&location, value, comparand);
}

interlocked::llong_t interlocked::compare_exchange(llong_t& location, llong_t value, llong_t comparand) {
  return InterlockedCompareExchange64((llong_t*)&location, value, comparand);
}

#pragma warning(push)
#pragma warning(disable:4302)
#pragma warning(disable:4311)
#pragma warning(disable:4312)
void* interlocked::compare_exchange(void*& location, void* value, void* comparand) {
  if (sizeof(void*) == 4)
    return (void*)InterlockedCompareExchange((long*)&location, (long)value, (long)comparand);
  return (void*)InterlockedCompareExchange64((long long*)&location, (long long)value, (long long)comparand);
}
#pragma warning(pop)

int32_t interlocked::decrement(int32_t& location) {
  return InterlockedDecrement((long*)&location);
}

int64_t interlocked::decrement(int64_t& location) {
  return InterlockedDecrement64((long long*)&location);
}

int32_t interlocked::exchange(int32_t& location, int32_t value) {
  return InterlockedExchange((long*)&location, value);
}

int64_t interlocked::exchange(int64_t& location, int64_t value) {
  return InterlockedExchange64((long long*)&location, value);
}

interlocked::llong_t interlocked::exchange(llong_t& location, llong_t value) {
  return InterlockedExchange64((llong_t*)&location, value);
}

#pragma warning(push)
#pragma warning(disable:4302)
#pragma warning(disable:4311)
#pragma warning(disable:4312)
void* interlocked::exchange(void*& location, void* value) {
  if (sizeof(void*) == 4)
    return (void*)InterlockedExchange((long*)&location, (long)value);
  return (void*)InterlockedExchange64((long long*)&location, (long long)value);
}
#pragma warning(pop)

int32_t interlocked::increment(int32_t& location) {
  return InterlockedIncrement((long*)&location);
}

int64_t interlocked::increment(int64_t& location) {
  return InterlockedIncrement64((long long*)&location);
}
