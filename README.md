# cp-library

[![LICENSE](https://img.shields.io/github/license/ryoga-exe/cp-library)](https://github.com/Ryoga-exe/cp-library/blob/main/LICENSE)
[![Issues](https://img.shields.io/github/issues/ryoga-exe/cp-library)](https://github.com/Ryoga-exe/cp-library/issues)
![Lines of code](https://img.shields.io/tokei/lines/github/ryoga-exe/cp-library)
[![Deploy to GitHub Pages](https://github.com/Ryoga-exe/cp-library/actions/workflows/gh-pages.yml/badge.svg)](https://github.com/Ryoga-exe/cp-library/actions/workflows/gh-pages.yml)

[![Twitter Follow](https://img.shields.io/twitter/follow/Ryoga_exe?color=1DA1F2&logo=twitter&style=flat)](https://twitter.com/intent/follow?screen_name=Ryoga_exe)
[![AtCoder Ryoga_exe](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FRyoga_exe)](https://atcoder.jp/users/Ryoga_exe)

## What is this?｜これは何？

[Document](ryoga-exe.github.io/cp-library/)

Ryoga.exe's Library and Code snippets for competitive programming.

For use with `C++17 (GCC 9.2.1)`.

Ryoga.exe の競プロ用ライブラリ・スニペット

`C++17 (GCC 9.2.1)` での使用を想定しています。

## Generate Snippet｜スニペットを生成する

```bash
# Install Dependencies (it requires PyYAML to parse yaml files)
pip install PyYAML

# Run!
python generate-snippet.py
```

## Add new file to library｜ライブラリ追加手順

1. ファイル (`src/<CATEGORY>/<PATH>.hpp` 等) を追加
  
    prefix などは以下の通りに記述して設定する
    ```cpp
    /// @prefix <>
    /// @description <>
    /// @isFileTemplate false
    ```

    ここで以下の形式の `start` がない場合はファイルのはじめからス ニペットに登録される、ある場合は `start` の次の行から登録され  る
    ```cpp
    /// start
    ```
    
    `src/` 直下に新たにディレクトリを作成してその中にファイルを追加 した場合、`config.yml` を更新する

2. ドキュメントを追加

## Add Releases｜リリースを追加

```bash
git tag v1.0.0
git push origin --tag
```

## License｜ライセンス

MIT License. [LICENSE file](https://github.com/Ryoga-exe/cp-library/blob/main/LICENSE) for more information.
