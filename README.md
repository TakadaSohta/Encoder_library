# Encoder_AHLab

**Version:** 1.0  
**Author:** Sohta Takada  
**Email:** takada@ah.iit.tsukuba.ac.jp 
**License:** MIT

---

## Overview / 概要
The `Encoder_AHLab` library provides functionality for measuring position, direction, and degree using rotary encoders. This library is designed for use in Arduino-based projects and supports easy integration with hardware using interrupt-based mechanisms.  
`Encoder_AHLab`ライブラリは、ロータリーエンコーダを使用して位置、方向、角度を測定する機能を提供します。このライブラリはArduinoをベースとしたプロジェクトで使用するために設計されており、割り込みベースの仕組みを用いたハードウェアとの簡単な統合をサポートします。

---

## Features / 特徴
- **Position Measurement / 位置測定:** Track the encoder’s position using interrupts.  
  割り込みを使用してエンコーダの位置を追跡。
- **Direction Detection / 回転方向の検出:** Determine the rotation direction of the encoder.  
  エンコーダの回転方向を検出。
- **Degree Calculation / 回転角度の計算:** Compute the rotational angle in degrees.  
  回転角度を度単位で計算。

---

## Installation / インストール方法
1. Download or clone this repository: [Encoder_AHLab](https://github.com/TakadaSohta/Encoder_AHLab).  
   このリポジトリをダウンロードまたはクローンします: [Encoder_AHLab](https://github.com/TakadaSohta/Encoder_AHLab)。
2. Copy the repository folder into your Arduino `libraries` directory.  
   リポジトリフォルダをArduinoの`libraries`ディレクトリにコピーします。
3. Restart your Arduino IDE to load the library.  
   Arduino IDEを再起動してライブラリを読み込みます。

---

## Requirements / 必要条件
- **Dependencies / 依存関係:**
  - `Wire` library  
    `Wire`ライブラリ
- **Core Dependency / コア依存関係:**
  - Arduino core version 1.5.0 or higher  
    Arduinoコアバージョン1.5.0以上

---

## Usage / 使用方法
### 1. Include the Library / ライブラリをインクルード
Include the `Encoder_AHLab` library in your Arduino sketch:  
Arduinoスケッチに`Encoder_AHLab`ライブラリをインクルードします:
```cpp
#include <Encoder_AHLab.h>
```

### 2. Initialize the Encoder / エンコーダの初期化
Create an instance of the `Encoder` class, specifying the encoder pins:  
エンコーダのピンを指定して`Encoder`クラスのインスタンスを作成します:
```cpp
Encoder encoder(21, 22); // Pin A = 21, Pin B = 22
```

### 3. Setup the Encoder / エンコーダの設定
Call `setupEncoder` in the `setup` function to initialize the encoder:  
`setup`関数内で`setupEncoder`を呼び出してエンコーダを初期化します:
```cpp
void setup() {
    encoder.setupEncoder();
}
```

### 4. Read Encoder Data / エンコーダデータの読み取り
Use the provided getter functions to access encoder information:  
提供されているゲッター関数を使用してエンコーダ情報にアクセスします:
```cpp
int position = encoder.getEncPosition();
int direction = encoder.getEncDirection();
double degree = encoder.getEncDegree();
```

---

## API Reference / APIリファレンス
### Class: `Encoder` / クラス: `Encoder`
#### Constructor / コンストラクタ
```cpp
Encoder(int pinA, int pinB);
```
- **pinA:** GPIO pin connected to Encoder A.  
  エンコーダAに接続されるGPIOピン。
- **pinB:** GPIO pin connected to Encoder B.  
  エンコーダBに接続されるGPIOピン。

#### Public Methods / 公開メソッド
- `void setupEncoder();`
  - Initializes the encoder pins and attaches interrupts.  
    エンコーダピンを初期化し、割り込みを設定します。

- `int getEncPosition() const;`
  - Returns the current encoder position.  
    現在のエンコーダ位置を返します。

- `int getEncDirection() const;`
  - Returns the current encoder direction:  
    現在のエンコーダ方向を返します:
    - `1` for clockwise.  
      時計回りの場合は`1`
    - `-1` for counter-clockwise.  
      反時計回りの場合は`-1`

- `double getEncDegree() const;`
  - Returns the current encoder rotation in degrees.  
    現在のエンコーダ回転角度を度単位で返します。

---

## Example / 例
Below is a simple example sketch demonstrating the use of `Encoder_AHLab`:  
以下は`Encoder_AHLab`の使用方法を示した簡単な例です:
```cpp
#include <Encoder_AHLab.h>

Encoder encoder(21, 22);

void setup() {
    Serial.begin(9600);
    encoder.setupEncoder();
}

void loop() {
    Serial.print("Position: ");
    Serial.println(encoder.getEncPosition());
    Serial.print("Direction: ");
    Serial.println(encoder.getEncDirection());
    Serial.print("Degree: ");
    Serial.println(encoder.getEncDegree());
    delay(500);
}
```

---

## Files in This Repository / リポジトリ内のファイル
### Source Code / ソースコード
- **`Encoder_AHLab.cpp`**: Implementation of the `Encoder` class.  
  `Encoder`クラスの実装。
- **`Encoder_AHLab.h`**: Header file defining the `Encoder` class.  
  `Encoder`クラスを定義するヘッダファイル。

### Examples / 例
- **`simple.ino`**: A simple example demonstrating basic usage of the library.  
  ライブラリの基本的な使用方法を示す簡単な例。

### Metadata / メタデータ
- **`library.properties`**: Contains metadata for Arduino Library Manager compatibility.  
  Arduinoライブラリマネージャ互換性のためのメタデータを含む。
- **`keyword.txt`**: Defines syntax highlighting for Arduino IDE.  
  Arduino IDEの構文ハイライトを定義。

---

## License / ライセンス
This project is licensed under the MIT License. See the `LICENSE` file for details.  
このプロジェクトはMITライセンスの下でライセンスされています。詳細は`LICENSE`ファイルを参照してください。

---

## Contact / 連絡先
For any questions or suggestions, please contact:  
ご質問や提案がある場合は以下にご連絡ください:
- **Author / 著者:** Sohta Takada  
- **Email / メール:** takada@ah.iit.tsukuba.ac.jp

