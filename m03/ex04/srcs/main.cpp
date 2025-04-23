#include "ILogger.hpp"
#include <vector>

int main() {
    FileLogger*      logger0 = new FileLogger("log.txt");
    OStreamLogger*   logger1 = new OStreamLogger(std::cout);

    std::vector<ILogger*> loggers;

    loggers.push_back(logger1);
    loggers.push_back(logger0);

    std::string s[] = {
        "hello\n",
        "how\n",
        "are\n",
        "you\n"
    };

    for (size_t i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
        for (size_t j = 0; j < loggers.size(); j++) {
            loggers[j]->write(s[i]);
        }
    }

    delete logger0;
    delete logger1;

    return 0;
}