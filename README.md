RTOS_Guardian_BMS 🔋
本项目是一款基于 STM32F411 开发板和 NXP GUI Guider 设计的工业级电池管理系统（BMS）抬头显示（HUD）原型。

🌟 项目核心特性
嵌入式实时操作系统：基于 FreeRTOS 实现多任务并行管理。

专业级 UI 交互：采用 LVGL v8.3.9 图形库，通过 GUI Guider 实现平滑的页面跳转与报警日志管理。

高性能显示驱动：适配 1.69 英寸 ST7789 LCD 屏幕，支持高频 SPI 驱动。

精准触控体验：集成 CST816T 电容触摸屏驱动，支持中断触发（EXTI）与手势识别。

健康监测算法：内置电池状态（SOC/SOH）计算逻辑，支持 CAN 总线数据解析。

📁 目录结构说明
Middlewares/LVGL/LVGL_ui：由 GUI Guider 生成的 UI 核心逻辑，包含：

generated/：自动生成的 UI 布局代码（如主页 screen_lcd 与报警页 screen_alarm）。

custom/：用户自定义 C 逻辑扩展及 custom.h。

BSP/：硬件抽象层驱动，包含 ST7789 屏幕及 CST816T 触摸芯片。

Core/Src/freertos.c：系统初始化任务与 LVGL 刷新循环。

🚀 快速上手
硬件连接：确保 SPI 频率配置在 25MHz 以上，并开启 DMA 传输以解决刷新“拉窗帘”效应。

环境配置：

IDE：Keil MDK v5.06。

UI 工具：NXP GUI Guider。

编译与烧录：

在 Keil 中 Include Paths 需手动添加 custom 和 generated 文件夹路径。

若编译报 gui_guider.h 缺失，请检查 #include 路径是否正确。

🛠️ 当前开发进度
[x] 适配 CST816T 电容屏驱动。

[x] 实现主界面与系统报警日志页面的双向跳转。

[x] 全面切换为英文 UI 界面并关闭性能监测（Debug info）。

[ ] 优化 SPI DMA 刷新性能（目前存在约 2 秒的延迟，持续调试中）。
