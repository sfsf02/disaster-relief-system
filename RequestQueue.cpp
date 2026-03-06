#include "RequestQueue.h"
#include <stdexcept>

using namespace std;

void RequestQueue::addRequest(const ReliefRequest& req)
{
    requests.push(req);
}

ReliefRequest RequestQueue::getNextRequest()
{
    if (requests.empty())
    {
        throw runtime_error("RequestQueue is empty");
    }

    ReliefRequest topRequest = requests.top();
    requests.pop();
    return topRequest;
}

bool RequestQueue::isEmpty() const
{
    return requests.empty();
}

size_t RequestQueue::size() const
{
    return requests.size();
}