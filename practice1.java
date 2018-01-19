package com.desperado.practice1;

/**
 * Created by desperado on 18-1-17.
 * 单例的五种写法
 */

public class SingletonTest {

    private SingletonTest() {
    }

    private static SingletonTest INSTANCE;

    /**
     * 懒汉 线程不安全
     *
     * @return
     */
    public static SingletonTest getInstance1() {
        if (INSTANCE == null) {
            INSTANCE = new SingletonTest();
        }
        return INSTANCE;
    }

    /**
     * 线程安全, 但是性能不好, 每次都需要访问都需要同步
     *
     * @return
     */
    public static synchronized SingletonTest getInstance2() {
        if (INSTANCE == null) {
            INSTANCE = new SingletonTest();
        }
        return INSTANCE;
    }

    /**
     * 推荐, 可以保证线程安全和性能
     *
     * @return
     */
    public static SingletonTest getInstance3() {
        return InstanceHolder.INSTANCE;
    }

    private static class InstanceHolder {
        private static SingletonTest INSTANCE = new SingletonTest();
    }

    /**
     * DLC 推荐, 不过只能在1.5后才能工作, 1.4以下是不能保证线程安全的.
     */
    private static volatile SingletonTest SINGLETON;

    public static SingletonTest getInstance4() {
        if (SINGLETON == null) {
            synchronized (SingletonTest.class) {
                if (SINGLETON == null) {
                    SINGLETON = new SingletonTest();
                }
            }
        }
        return SINGLETON;
    }

    /**
     * 推荐, 枚举单例
     */
    enum SingleTon {
        SINGLE_TON;
    }
}
