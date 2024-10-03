# コンパイラとフラグの設定
CC = gcc
CFLAGS = -Wall -g -Iinclude  # 共通ヘッダファイルのパス

# ソースファイルとオブジェクトファイルの設定
SERVER_SRC = server/main.c lib/utils.c
CLIENT_SRC = client/main.c lib/utils.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# 出力ファイル名
SERVER_TARGET = echo_server
CLIENT_TARGET = simple_client

# デフォルトターゲット
all: $(SERVER_TARGET) $(CLIENT_TARGET)

# サーバーバイナリ生成ルール
$(SERVER_TARGET): $(SERVER_OBJ)
	$(CC) -o $@ $^

# クライアントバイナリ生成ルール
$(CLIENT_TARGET): $(CLIENT_OBJ)
	$(CC) -o $@ $^

# オブジェクトファイル生成ルール
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# サーバー用ビルドルール
.PHONY: server
server: $(SERVER_TARGET)

# クライアント用ビルドルール
.PHONY: client
client: $(CLIENT_TARGET)

# クリーンアップルール
.PHONY: clean
clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_TARGET) $(CLIENT_TARGET)

# ソースファイルが存在するディレクトリを指定
VPATH = server:client:lib
