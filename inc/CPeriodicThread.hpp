
#include <thread>

class CPeriodicThread
{
public:

    CPeriodicThread(std::function<void()>& f, const unsigned int periodicityMilliseconds)
        : m_thread(std::jthread(CPeriodicThread::periodicThread, this))
        , m_periodicity(periodicity)
        , m_func(f)
    {
    }

    ~CPeriodicThread(void)
    {
        m_thread.request_stop();
    }

private:

    void periodicThread(void)
    {
        while(!m_thread.request_stop())
        {

        }
    }

    std::jthread m_thread;
    const unsigned int m_periodicity;
    std::function<void()> m_func;
};
