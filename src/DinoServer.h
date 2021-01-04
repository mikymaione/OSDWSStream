#pragma once

#ifndef SRC_DINOSERVER_H
#define SRC_DINOSERVER_H

#include "server_ws_impl.hpp"

#include <functional>

class DinoServer : public webpp::ws_server
{
public:
    DinoServer(std::function<void(DinoServer *)> callBack)
            : callBack(callBack)
    {}

protected:
    void accept();

private:
    std::function<void(DinoServer *)> callBack;
};

#endif //SRC_DINOSERVER_H