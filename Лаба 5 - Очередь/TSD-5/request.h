#ifndef REQUEST_H
#define REQUEST_H

class Request {
    double rAddTime;
    double rProcessingTime;
    int rProcessingsCount;
    void Generate();
public:
    Request();
    double AddTime();
    double ProcessingTime();
    int incProcessingsCount();
    static const double MinAddTime = 0;
    static const double MaxAddTime = 6;
    static const double MinProcessingTime = 0;
    static const double MaxProcessingTime = 1;
};

#endif // REQUEST_H
