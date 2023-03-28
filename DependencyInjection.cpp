#include <iostream>
using namespace std;

// Interface for Logger
__interface ILogger
{
    void Log(const string& message);
};

// ConsoleLogger implementation of ILogger interface
class ConsoleLogger : public ILogger
{
public:
    void Log(const string& message) override
    {
        cout << "[ConsoleLogger:] " << message << "\n";
    }
};

// FileLogger implementation of ILogger interface
class FileLogger : public ILogger
{
public:
    void Log(const string& message) override
    {
        // Write the message to a file
        // ...
        cout << "[FileLogger:] " << message << "\n";
    }
};

// DatabaseLogger implementation of ILogger interface
class DatabaseLogger : public ILogger
{
public:
    void Log(const string& message) override
    {
        // Write the message to a database
        // ...
        cout << "[DatabaseLogger:] " << message << "\n";
    }
};

// Interface for User class
class Application
{
private:
    ILogger* logger;

public:
    Application(ILogger* logger) : logger(logger) {}

    void DoSomething()
    {
        logger->Log("Logger usage demo");
    }
};

int main()
{
    // Create the logger
    DatabaseLogger logger;

    // Create the user with the logger dependency
    Application app(&logger);

    // Call the SayHello method on the user
    app.DoSomething();
}

/*
Этот код демонстрирует реализацию паттерна Dependency Injection
с помощью интерфейса ILogger, а также реализации ILogger для трех разных типов
логгирования: ConsoleLogger, FileLogger и DatabaseLogger.

В функции main() создается экземпляр DatabaseLogger, и затем
создается экземпляр Application, который использует этот логгер
в качестве зависимости. Вызов метода DoSomething() на app в конечном итоге
вызывает метод Log() на экземпляре DatabaseLogger.

Обратите внимание, что зависимость от ILogger передается экземпляру Application
через конструктор. Это означает, что если мы захотим изменить логгер в будущем,
мы можем создать экземпляр другого типа логгера и передать его
в качестве зависимости при создании экземпляра Application. Это делает наш код
более гибким и удобным для поддержки в будущем.

Кроме того, здесь используется указатель ILogger* в качестве типа зависимости.
Это означает, что мы можем передавать как экземпляры объектов, так и указатели
на них. Здесь используется указатель на DatabaseLogger, но мы могли бы
использовать также и указатель на ConsoleLogger или FileLogger, если бы
это было необходимо.
*/

// https://en.wikipedia.org/wiki/Dependency_injection

// https://xufocoder.medium.com/a-quick-intro-to-dependency-injection-what-it-is-and-when-to-use-it-de1367295ba8

/*
В разработке программного обеспечения, внедрение зависимостей это такая техника,
где посредством одного объекта (или статического метода) предоставляются
зависимости другого объекта. Зависимость — это объект, который может быть
использован (как сервис).
*/