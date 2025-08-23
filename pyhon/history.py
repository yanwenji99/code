
import pyautogui
import time
import random
import pygetwindow as gw
import os

# 配置参数
total_minutes = 50  # 需要完成的总分钟数
scroll_interval = 30    # 基础滚动间隔（秒）
screen_padding = 100    # 页面边缘留白防止越界
rect_width = 200        # 矩形的宽度
rect_height = 200       # 矩形的高度

def main():
    # 找到企业微信窗口并激活
    try:
        wecom_window = gw.getWindowsWithTitle('企业微信')[0]
        wecom_window.activate()
    except IndexError:
        print("未找到企业微信窗口，请确保企业微信已打开。")
        return

    # 如果企业微信窗口被最小化，尝试将其移动到屏幕中央并最大化
    if wecom_window.isMinimized:
        screen_w, screen_h = pyautogui.size()
        wecom_window.moveTo(int(screen_w / 2), int(screen_h / 2))
        wecom_window.maximize()

    # 计算程序运行时间
    start_time = time.time()
    end_time = start_time + total_minutes * 60

    print("程序启动，5秒后开始运行...（请确保窗口在前台）")
    time.sleep(5)

    try:
        while time.time() < end_time:
            # 获取屏幕尺寸
            screen_w, screen_h = pyautogui.size()

            # 生成随机偏移量
            offset_x = random.randint(-rect_width // 2, rect_width // 2)
            offset_y = random.randint(-rect_height // 2, rect_height // 2)

            # 计算鼠标位置
            rand_x = int(screen_w / 2) + offset_x
            rand_y = int(screen_h / 2) + offset_y

            # 平滑移动鼠标到随机位置
            pyautogui.moveTo(rand_x, rand_y, duration=random.uniform(0.3, 0.7))

            # 执行随机滚动操作（负数表示向下滚动）
            scroll_amount = -random.randint(1000, 3000)
            pyautogui.scroll(scroll_amount)

            # 在滚动后点击一下
            pyautogui.click()
            #计算当前时间用了多少分钟
            time_temp = (time.time() - start_time) / 60
            print(f"到目前为止总共运行时间：{time_temp:.1f} 分钟")
            # 随机等待时间（增加不可预测性）
            wait_time = 10 + random.uniform(-1, 1)
            print(f"下次操作在 {wait_time:.1f} 秒后")
            time.sleep(wait_time)

    except KeyboardInterrupt:
        print("\n程序被手动终止")
        # 不执行关机操作，直接返回
        elapsed = (time.time() - start_time) / 60
        print(f"总共运行时间：{elapsed:.1f} 分钟")
        return

    elapsed = (time.time() - start_time) / 60
    print(f"总共运行时间：{elapsed:.1f} 分钟")
    os.system("shutdown /s /t 1")  # 关机命令
if __name__ == "__main__":
    main()