#pragma once
#include <queue>
#include "ReliefRequest.h"

using namespace std;

class RequestQueue
{
private:
    priority_queue<ReliefRequest> requests;

public:
    // Add request to queue (const reference avoids copying)
    void addRequest(const ReliefRequest& req);

    // Get highest priority request
    ReliefRequest getNextRequest();

    // Check if queue is empty
    bool isEmpty() const;

    // Optional: check number of requests
    size_t size() const;
};