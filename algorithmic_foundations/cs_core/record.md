# Record
https://en.wikipedia.org/wiki/Record_(computer_science)
https://www.quora.com/What-is-the-definition-of-a-record-data-structures

この性質はTupleやStructにもあてはまるか？

JavaのRecordはほぼTupleに等しいか？
https://docs.oracle.com/javase/jp/15/language/records.html

データベースのRecord以外にRecordを表す概念はあるか？


## explain its definition, properties, representation(s), and associated ADT operations.
- **Definition**: レコードは異なるデータ型を持つことができるフィールドの集合で、通常は固定された数と順序で構成される。オブジェクト指向プログラミングではメンバーとも呼ばれる。

- **Properties**: レコードは異質なデータ型であり、フィールドごとに異なるデータ型を持つことができる。レコードタイプはこれらの値と変数を記述するデータ型。
- **Representations**: レコードはメモリ内や大量記憶装置に存在でき、多くのデータ構造、特にリンクされたデータ構造の基本的な構成要素。
- **Associated ADT operations**: レコード型の宣言、レコード値の構築、フィールドの選択、レコード値の変数への割り当て、レコードの等価性比較。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- **Declaration**: 新しいレコード型を宣言し、各フィールドの位置、型、名前を定義する。
- **Construction**: 与えられたフィールド値からレコード値を構築する。
- **Selection**: 明示的な名前でレコードのフィールドを選択する。
- **Assignment**: レコード値をレコード変数に割り当てる。
- **Comparison**: 二つのレコードが等しいかどうかを比較する。
