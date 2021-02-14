namespace lambda
{

template <typename Derived>
struct LambdaBase
{
protected:
    ~LambdaBase() = default;

public:
    const Derived& derived()
    {
        return static_cast<const Derived&>(*this);
    }
};

template <typename ConstType>
struct LambdaConst : public LambdaBase<LambdaConst<ConstType>>
{
    using ResultType = ConstType;

    LambdaConst(const ConstType& value) : result(value)
    {
    }

    template <typename... Args>
    ResultType operator()(Args&&...)
    {
        return result;
    }

private:
    ConstType result;
};

}  // namespace lambda