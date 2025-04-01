def add_two_numbers(a, b):
    """
    计算两个数字的和。

    参数:
    a (float): 第一个数字
    b (float): 第二个数字

    返回:
    float: 两个数字的和
    """
    return a + b

def main():
    try:
        # 获取用户输入
        num1 = float(input("请输入第一个数字: "))
        num2 = float(input("请输入第二个数字: "))

        # 计算两数之和
        result = add_two_numbers(num1, num2)

        # 输出结果
        print(f"两个数字的和是: {result}")
    except ValueError:
        print("输入无效，请输入数字。")

if __name__ == "__main__":
    main()