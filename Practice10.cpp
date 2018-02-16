/**
 * 题目: 实现函数 double power(double base, double exponent), 求bade的exponent次方, 不得使用库函数, 同时不需要考虑大数问题
 *
 * 分析: 题目不难, 但是要考虑到特殊值情况以及错误的处理
 */

bool g_Invalid_Input = false;

int is_equal(double num1, double num2) {
    if ((num1 - num2 > -0.00000001) && (num1 - num2 < 0.00000001)) {
        return 1;
    } else {
        return 0;
    }
}

double power_with_unsigned_exponent(double base, double exponent) {
    double r = 1.0;
    for (int i = 0; i <= exponent; ++i) {
        r *= base;
    }
    return r;
}

double power(double base, double exponent) {
    g_Invalid_Input = false;

    if (is_equal(base, 0.0) && exponent < 0) { //如果底数为0, 且指数为负数, 没有数学意义
        g_Invalid_Input = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int) exponent;

    if (exponent < 0) {
        absExponent = (unsigned int) (-exponent); //求指数的绝对值
    }
    double r = power_with_unsigned_exponent(base, absExponent);

    if (exponent < 0) {
        r = 1.0 / r; //求倒数
    }
    return r;
}
