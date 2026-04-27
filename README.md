# Roadmap

## 你的優勢（比你想像的多）

- Go 語言底層思維強，看過 socket accept loop
- 自己設計過微服務框架，理解服務拆分概念
- C++ 有物件導向基礎
- 有 IPC 的實際使用經驗（只是不知道名詞）
- 理解 cross-compilation 概念
- 習慣讀原始碼、有 debug 思維
- 手上有 Raspberry Pi 400
- 每天 6 小時、裸辭全力衝

## 你的劣勢（需要在 1 個月內補）

- Linux 指令列只有基礎
- 沒有 C++ 實戰經驗
- systemd、dbus、IPMI、Redfish 全部陌生
- 沒有 GitHub 作品集
- 伺服器硬體概念為零

---

## 1 個月 Roadmap

我把 1 個月分成 **4 週**，每週有明確目標。

---

### 第 1 週：打地基（Linux + C++ 實戰）

**目標：讓你在 Raspberry Pi 上有感覺**

每天任務：
- **Day 1-2：Linux 指令列強化**
  - 學會：`ssh`、`ps`、`top`、`journalctl`、`systemctl`、`chmod`、`grep`、`find`
  - 工具：在 Raspberry Pi 上實際操作，不要用虛擬機
  - 資源：[Linux Journey](https://linuxjourney.com)（免費、互動式）

- **Day 3-4：systemd 實戰**
  - 自己寫一個 `.service` 檔案，讓一個簡單的 C++ 程式開機自動執行
  - 這個動作會把 Linux + C++ + systemd 三件事串在一起

- **Day 5-6：C++ 補強**
  - 重點補：`smart pointer`、`std::vector`、`std::map`、lambda
  - 資源：[learncpp.com](https://learncpp.com)，直接跳到你還不熟的章節
  - 不要從頭讀，你已經有 B 級基礎

- **Day 7：建立 GitHub**
  - 把這週做的東西全部推上去
  - 寫清楚 README：「我在學 openBMC，這是我的學習紀錄」

**第 1 週結束的檢查點：**
> 能不能在 Raspberry Pi 上，用 C++ 寫一個程式，讓它用 systemd 管理、開機自動啟動、並且用 `journalctl` 看到它的 log？

---

### 第 2 週：核心概念（IPMI + Redfish + dbus）

**目標：理解 openBMC 的三個核心協定**

- **Day 8-9：IPMI 概念**
  - 不需要實作，先讀懂概念
  - IPMI 是什麼：BMC 跟主機溝通的標準協定
  - 資源：讀 openBMC 的官方 wiki：[github.com/openbmc/docs](https://github.com/openbmc/docs)

- **Day 10-11：Redfish API**
  - 你有後端背景，這個最容易上手
  - 用 `curl` 打看看公開的 Redfish mock server
  - 理解 Redfish 的資源樹結構（Chassis、Systems、Managers）

- **Day 12-13：dbus 概念 + 實作**
  - 這是最難的一週，要有心理準備
  - 先讀概念：dbus 是 Linux 上的 IPC，類似你用過的 RabbitMQ 但更底層
  - 實作：在 Raspberry Pi 上跑一個簡單的 dbus service，用 C++ 寫

- **Day 14：整理 + 推 GitHub**
  - 把這週學的東西整理成筆記推上 GitHub

**第 2 週結束的檢查點：**
> 能不能用自己的話解釋：IPMI 是什麼、Redfish 跟一般 REST API 差在哪、dbus 解決了什麼問題？

---

### 第 3 週：動手做（openBMC 編譯 + 功能模組）

**目標：真正碰到 openBMC 的程式碼**

- **Day 15-16：編譯 openBMC**
  - 這是最耗時間的一步，openBMC 用 Yocto 編譯，第一次可能要幾個小時
  - 跑在 QEMU 模擬器上（不需要真實伺服器硬體）
  - 資源：[openBMC 官方 Getting Started](https://github.com/openbmc/openbmc)

- **Day 17-18：讀 openBMC 的一個子專案**
  - 建議從 `phosphor-dbus-interfaces` 或 `phosphor-fan-presence` 開始
  - 這兩個相對簡單，而且能看到 dbus + systemd 怎麼配合

- **Day 19-20：做一個小修改**
  - 在現有的 openBMC 模組上做一個小改動
  - 例如：改一個 sensor 的回報值、加一個新的 dbus property
  - 把這個改動推上你的 GitHub fork

- **Day 21：整理作品集**
  - 把你的 GitHub 整理乾淨
  - 寫一篇說明文件：你改了什麼、為什麼這樣改

**第 3 週結束的檢查點：**
> 有沒有辦法在 QEMU 上跑起 openBMC，並且展示一個你自己做的小改動？

---

### 第 4 週：面試準備 + 投履歷

**目標：把你的成果變成可以談的東西**

- **Day 22-23：整理履歷**
  - 重點：把你這 3 週做的東西寫進去
  - 格式：「在 Raspberry Pi 上建立 C++ systemd service」、「修改 openBMC phosphor 模組的 dbus interface」
  - 這些比「熟悉 openBMC」更有說服力

- **Day 24-25：準備面試常見問題**
  - Linux process vs thread
  - dbus 是什麼、解決什麼問題
  - IPMI 跟 Redfish 的差異
  - C++ smart pointer 是什麼、為什麼用
  - systemd service 怎麼寫

- **Day 26-27：投履歷**
  - 目標公司優先順序：
    1. 緯穎、廣達、緯創（系統廠，門檻相對低）
    2. 信驊科技（IC 設計，門檻高但值得試）
    3. AMI、Super Micro 台灣辦公室（外商）

- **Day 28-30：面試 + 持續補強**
  - 面試過程中把問到不會的問題記下來，當天補學

---

## 最後一件重要的事

1 個月是非常緊的時間表，我必須誠實告訴你：

> 如果第 3 週的 openBMC 編譯和修改能順利完成，你就有資格投履歷了。但能不能在 1 個月內**拿到 offer**，還取決於公司的面試流程速度。

所以我建議你把目標調整成：

- **第 1 個月**：完成 roadmap，投出第一批履歷
- **第 2 個月**：面試、補強面試中發現的弱點

這樣比較實際，也不會因為時間壓力影響學習品質。
