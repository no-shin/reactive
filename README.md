# Interactive Problem Template

インタラクティブ問題をローカルでテストするためのテンプレートです。

## 構成

```text
.
├── gen.cpp       # テストケース生成器
├── gen.sh        # テストケース生成スクリプト
├── judge.cpp     # ローカルジャッジ
├── solve.cpp     # 解答プログラム
├── reactive.py   # judge と solve を中継するスクリプト
├── run.sh        # 全テストケースを実行
└── data/
    ├── 001.in
    ├── 002.in
    └── ...
```

---

## 必要環境

- g++
- Python 3

---

## テストケース生成

`gen.cpp` をコンパイルして `data/` 以下にテストケースを生成します。

```bash
./gen.sh
```

生成数や生成方法は `gen.sh` および `gen.cpp` を編集してください。

---

## テスト実行

すべてのテストケースを実行します。

```bash
./run.sh
```

`run.sh` は

1. `judge.cpp`
2. 解答（一つ上のディレクトリに `main.cpp` があればそれ、なければ `solve.cpp`）

をコンパイルし、`data/*.in` を順番に実行します。
正解したケースは `PASS data/001.in` の1行だけ、不正解のケースは通信ログと `FAIL` を表示し、最後に `n / m passed.` を表示します。

どのディレクトリから実行しても構いません。

```text
icpc/A/
├── main.cpp      # 解答
└── reactive/     # このテンプレートをコピー
```

```bash
cd icpc/A
./reactive/run.sh
```

judge は **不正解なら 0 以外で終了** してください（`reactive.py` が judge / solve の終了コードで正誤を判定します）。

---

## 個別テスト

特定のテストケースだけ実行したい場合

```bash
python3 reactive.py data/001.in
```

---

## judge の仕様

入力ファイルはコマンドライン引数で受け取ります。

```cpp
int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ...
}
```

標準入力 (`cin`) は **solve との通信専用**です。

---

## solve の注意

インタラクティブ問題では必ず出力を flush してください。

```cpp
cout << answer << endl;
```

または

```cpp
cout << answer << '\n';
cout.flush();
```

flush を忘れると `judge` が入力を受け取れず停止します。

---

## reactive.py

`judge` と `solve` の標準入出力を接続し、通信内容をログ表示します。

例:

```text
[0.001] JUDGE→ 20
[0.001] SOLVE→ 50
[0.001] JUDGE→ LOWER
[0.001] SOLVE→ 25
[0.002] JUDGE→ CORRECT
```

これにより、インタラクティブな通信を確認しながらデバッグできます。
