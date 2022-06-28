# ScissorGlue
DXライブラリを使用したブロック崩しを製作します。

doxygen　Javadocスタイルによるコメントを書く。

1．各ファイルの先頭に書くコメント

/**
* @file ファイル名 main.cppとか
* @brief ファイルの説明
* @author 作成者名　(Githubで管理するなら別に書かなくて良いけど、就活での提出見据えて)
* @date 作成日　(Githubで管理するなら別に書かなくて良いけど、就活での提出見据えて)
*
* @details 詳細説明（基本的には省略）
* @note 補足説明とかメモ（基本的には省略）
*/
2.各関数の前行に書くコメント

 /**
 * @brief 関数の説明
 * @param [引数の名前] 引数の説明　(\param[in]\param[out]という書き方もあるっぽいけど先輩が使ってない)
 * @return [型] 戻り値の説明(当然だけどvoid型なら書かない)
 */
3.変数、enumの書くコメント

/** 変数の説明 */
int a {0}
あるいは

int a {0};//<変数の説明(直後にコメントを書く場合は'<'を入れる)
そのほか、便利そうなところには/**~*/とか@briefでコメントを入れとく

命名規則 関数名、クラス名、メゾッド名 ・大文字から始める アッパーキャメル 変数　int _position _xPosition　ロウワーキャメルケース ローカル変数・引数　小文字

フォルダ分け ヘッダーファイルとソースファイルは同一のフィルタでまとめる

メソッドは50行目安で分けるようにする
