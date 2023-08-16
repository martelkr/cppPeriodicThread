
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

/**
 * @brief Create a C++20 periodic jthread
 * 
 */
class CPeriodicThread
{
public:

    /**
     * @brief Construct a new CPeriodicThread object
     * 
     * @param func Function to call periodically
     * @param periodicityMilliseconds The millisecond period at which to call the provided function
     */
    CPeriodicThread(std::function<void()>& func, const unsigned int periodicityMilliseconds)
        : m_thread([periodicityMilliseconds, func](std::stop_token stopToken)
        {
            const std::chrono::milliseconds period(periodicityMilliseconds);
            while(!stopToken.stop_requested())
            {
                func();
                std::this_thread::sleep_for(period);
            }
        })
    {
    }

    /**
     * @brief Destroy the CPeriodicThread object
     * 
     */
    ~CPeriodicThread(void)
    {
        m_thread.request_stop();
    }

private:

    /// @brief The jthread to contain the periodic function call
    std::jthread m_thread;
};
