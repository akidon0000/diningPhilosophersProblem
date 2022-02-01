echo "---------------エラー内容---------------"
# コンパイル
gcc -o solution solution.c
echo "---------------実行結果-----------------"
./solution

# 新しくできたファイルを削除
rm -f solution.out
