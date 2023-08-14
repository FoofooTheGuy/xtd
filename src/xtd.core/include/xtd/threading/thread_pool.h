/// @file
/// @brief Contains xtd::threading::thread_pool class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "registered_wait_handle.h"
#include "semaphore.h"
#include "thread.h"
#include "wait_callback.h"
#include "wait_or_timer_callback.h"
#include "../core_export.h"
#include "../static.h"
#include "../types.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread_pool activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread_pool pool threads.
  namespace threading {
    /// @brief Provides a pool of threads that can be used to execute tasks, post work items, process asynchronous I/O, wait on behalf of other threads, and process timers.
    /// @code
    /// class core_export_ thread_pool static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::threading::thread_pool
    /// @par Header
    /// @code #include <xtd/threading/thread_pool> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core threading
    /// @ingroup xtd_core threading
    /// @par Examples
    /// In the following example, the main application thread queues a method named ThreadProc to execute on a thread pool thread, sleeps for one second, and then exits. The ThreadProc method simply displays a message.
    /// @include thread_pool.cpp
    /// If you comment out the call to the xtd::threading::thread::sleep method, the main thread exits before method runs on the thread pool thread. The thread pool uses background threads, which do not keep the application running if all foreground threads have terminated. (This is a simple example of a race condition.)
    /// @remarks Many applications create threads that spend a great deal of time in the sleeping state, waiting for an event to occur. Other threads might enter a sleeping state only to be awakened periodically to poll for a change or update status information. The thread pool enables you to use threads more efficiently by providing your application with a pool of worker threads that are managed by the system. Examples of operations that use thread pool threads include the following:
    /// * When you create a xtd::threading::task::task or xtd::threading::task::task < result_t > object to perform some task asynchronously, by default the task is scheduled to run on a thread pool thread.
    /// * Asynchronous timers use the thread pool. Thread pool threads execute callbacks from the xtd::threading::timer class and raise events from the xtd::timers::timer class.
    /// * When you use registered wait handles, a system thread monitors the status of the wait handles. When a wait operation completes, a worker thread from the thread pool executes the corresponding callback function.
    /// * When you call the xtd::threading::thread_pool::queue_user_work_item method to queue a method for execution on a thread pool thread. You do this by passing the method a xtd::threading::wait_callback delegate. The delegate has the signature @verbatom using wait_callback = action<std::any> @endverbatim where state is an object that contains data to be used by the delegate. The actual data can be passed to the delegate by calling the xtd::threading::thread_pool::queue_user_work_item(xtd::threading::wait_callback, std::any) method.
    /// @note The threads in the managed thread pool are background threads. That is, their xtd::threading::thread::is_background properties are true. This means that a xtd::threading::thread_pool thread will not keep an application running after all foreground threads have exited.
    /// @remarks You can also queue work items that are not related to a wait operation to the thread pool. To request that a work item be handled by a thread in the thread pool, call the xtd::threading::thread_pool::queue_user_work_item method. This method takes as a parameter a reference to the method or delegate that will be called by the thread selected from the thread pool. There is no way to cancel a work item after it has been queued.
    /// @remarks Timer-queue timers and registered wait operations also use the thread pool. Their callback functions are queued to the thread pool.
    /// @remarks There is one thread pool per process.The default size of the thread pool for a process depends on several factors, such as the size of the virtual address space. A process can call the xtd::threading::thread_pool::gt_max_threads method to determine the number of threads. The number of threads in the thread pool can be changed by using the xtd::threading::thread_pool::set_max_threads method. Each thread uses the default stack size and runs at the default priority.
    /// @remarks The thread pool provides new worker threads or I/O completion threads on demand until it reaches the maximum for each category. When a maximum is reached, the thread pool can create additional threads in that category or wait until some tasks complete. The thread pool creates and destroys worker threads in order to optimize throughput, which is defined as the number of tasks that complete per unit of time. Too few threads might not make optimal use of available resources, whereas too many threads could increase resource contention.
    /// @note When demand is low, the actual number of thread pool threads can fall below the minimum values.
    /// @remarks You can use the xtd::threading::thread_pool::get_min_threads method to obtain these minimum values.
    /// @warning You can use the xtd::threading::thread_pool::set_min_threads method to increase the minimum number of threads. However, unnecessarily increasing these values can cause performance problems. If too many tasks start at the same time, all of them might appear to be slow. In most cases the thread pool will perform better with its own algorithm for allocating threads.
    class core_export_ thread_pool static_ {
      friend class registered_wait_handle;

      class asynchronous_io_thread_vector : public std::vector<thread> {
      public:
        asynchronous_io_thread_vector();
        asynchronous_io_thread_vector(size_t count);
        ~asynchronous_io_thread_vector();
      };

      template<typename T>
      struct thread_item : public object {
        thread_item() {}
        thread_item(const T& callback) : callback(callback) {}
        thread_item(const T& callback, std::any state) : callback(callback), state(&state) {}
        thread_item(const T& callback, std::any state, wait_handle& wait_object, int32 milliseconds_timeout_interval, bool execute_only_once) : callback(callback), state(state), wait_object(&wait_object), milliseconds_timeout_interval(milliseconds_timeout_interval), execute_only_once(execute_only_once) {}
        
        T callback;
        std::any state;
        wait_handle* wait_object = null;
        int32 milliseconds_timeout_interval;
        bool execute_only_once = true;
        bool unregistered = false;
        
        void run() {
          do {
            this->callback(state);
          } while (!execute_only_once);
        }
      };
      
      using thread_pool_item = thread_item<wait_callback>;
      using thread_pool_asynchronous_io_item = thread_item<wait_or_timer_callback>;
      using thread_pool_item_collection = std::vector<thread_pool_item>;
      using thread_pool_asynchronous_io_item_collection = std::vector<thread_pool_asynchronous_io_item>;

      class thread_vector : public std::vector<thread> {
      public:
        thread_vector();
        thread_vector(size_t count);
        ~thread_vector();
      };

    public:
      /// @brief Retrieves the difference between the maximum number of thread pool threads returned by the GetMaxThreads method, and the number currently active.
      /// @param worker_threads The number of available worker threads
      /// @param completion_port_threads The number of available asynchronous I/O threads.
      /// @exception ArgumentNullException The workerThreads or completionPortThreads param is null.
      /// @remarks When GetAvailableThreads returns, the variable specified by workerThreads contains the number of additional worker threads that can be started, and the variable specified by completionPortThreads contains the number of additional asynchronous I/O threads that can be started.
      static void get_available_threads(size_t& worker_threads, size_t& completion_port_threads);

      /// @brief Retrieves the number of requests to the thread pool that can be active concurrently. All requests above that number remain queued until thread pool threads become available.
      /// @param worker_threads The maximum number of worker threads in the thread pool.
      /// @param completion_port_threads The maximum number of asynchronous I/O threads in the thread pool.
      /// @exception ArgumentNullException The workerThreads or completionPortThreads param is null.
      /// @remarks When GetMaxThreads returns, the variable specified by workerThreads contains the maximum number of worker threads allowed in the thread pool, and the variable specified by completionPortThreads contains the maximum number of asynchronous I/O threads allowed in the thread pool.
      /// @remarks You can use the GetAvailableThreads method to determine the actual number of threads in the thread pool at any given time.
      /// @remarks You can use the SetMaxThreads to set the maximum number of worker threads and asynchronous I/O threads in the thread pool.
      static void get_max_threads(size_t& worker_threads, size_t& completion_port_threads);
      
      /// @brief Retrieves the number of idle threads the thread pool maintains in anticipation of new requests. Always 0 for both.
      /// @param worker_threads The maximum number of worker threads in the thread pool.
      /// @param completion_port_threads The maximum number of asynchronous I/O threads in the thread pool.
      /// @exception ArgumentNullException The workerThreads or completionPortThreads param is null.
      /// @remarks To develop in the future for optimization.
      static void get_min_threads(size_t& worker_threads, size_t& completion_port_threads);
      
      /// @brief Sets the number of requests to the thread pool that can be active concurrently. All requests above that number remain queued until thread pool threads become available.
      /// @param worker_threads The maximum number of worker threads in the thread pool.
      /// @param completion_port_threads The maximum number of asynchronous I/O threads in the thread pool.
      /// @return Boolean true if the change is successful; otherwise, false.
      /// @exception ArgumentOutOfRangeException if the workerThreads  is < 0 or > MaxThreads  - or - if the completionPortThreads  is < 0 or > MaxAsynchronousIoThreads.
      /// @remarks The maximum value that can be set is 256.
      /// @see MaxThreads
      /// @see MaxAsynchronousIoThreads
      static bool set_max_threads(size_t worker_threads, size_t completion_port_threads);
      
      /// @brief Sets the number of idle threads the thread pool maintains in anticipation of new requests.
      /// @param worker_threads The new minimum number of idle worker threads to be maintained by the thread pool.
      /// @param completion_port_threads The new minimum number of idle asynchronous I/O threads to be maintained by the thread pool.
      /// @return Boolean true if the change is successful; otherwise, false.
      /// @exception ArgumentOutOfRangeException if the workerThreads  is different of 0 - or - if the completionPortThreads  is different of 0.
      /// @remarks The only value that can be set is 0.
      /// @remarks To develop in the future for optimization.
      static bool set_min_threads(size_t worker_threads, size_t completion_port_threads);

    private:
      static void asynchronous_io_run();
      static void create_threads();
      static void create_asynchronous_io_threads();
      static void run();

      static semaphore  asynchronous_io_semaphore_;
      static asynchronous_io_thread_vector asynchronous_io_threads_;
      static bool closed_;
      static size_t max_threads_;
      static size_t max_asynchronous_io_threads_;
      static size_t min_threads_;
      static size_t min_asynchronous_io_threads_;
      static semaphore semaphore_;
      static thread_vector threads_;
      static thread_pool_item_collection thread_pool_items_;
      static object thread_pool_items_sync_root_;
      static thread_pool_asynchronous_io_item_collection thread_pool_asynchronous_io_items_;
      static object thread_pool_asynchronous_io_items_sync_root_;
    };
  }
}
