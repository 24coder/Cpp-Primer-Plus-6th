#include <iostream>
#include <memory>

// 抽象策略接口
class Strategy {
public:
    virtual void execute() const = 0;
    virtual ~Strategy() {}
};

// 具体策略 A
class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy A\n";
    }
};

// 具体策略 B
class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy B\n";
    }
};

// 上下文类
class Context {
private:
    std::unique_ptr<Strategy> strategy_;
public:
    explicit Context(std::unique_ptr<Strategy> strategy) : strategy_(std::move(strategy)) {}

    void set_strategy(std::unique_ptr<Strategy> strategy) {
        strategy_ = std::move(strategy);
    }

    void execute_strategy() const {
        if (strategy_) {
            strategy_->execute();
        } else {
            std::cout << "No strategy set\n";
        }
    }
};

int main() {
    // 手动创建 std::unique_ptr 实例
    Context context(std::unique_ptr<Strategy>(new ConcreteStrategyA()));
    context.execute_strategy();

    context.set_strategy(std::unique_ptr<Strategy>(new ConcreteStrategyB()));
    context.execute_strategy();

    return 0;
}