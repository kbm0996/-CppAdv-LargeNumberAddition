# 큰 수 덧셈
## 📢 개요
 C언어에서 각각의 자료형은 표현할 수 있는 값의 범위에는 한계가 있다.
 
| Data Type | Size | Range |
|:--------:|:--------:|--------|
| char | 1 Bytes | -128 ~ 127 |
| short | 2 Bytes | -32,768 ~ 32767 |
| int | 4 Bytes | -2,147,483,648 ~ 2,147,483,649 |
| long | 4 Bytes | -2,147,483,648 ~ 2,147,483,649 |
| unsigned char | 1 Bytes | 0 ~ 255 |
| unsigend short | 2 Bytes | 0 ~ 65,535 |
| unsigned int | 4 Bytes | 0 ~ 4,294,967,295 |
| unsigned long | 4 Bytes | 0 ~ 4,294,967,295 |
| float | 4 Bytes | 1.2E-38 ~ 3.4E38 |
| double | 8 Bytes | 2.2E-308 ~ 1.8E308 |

**table 1. DataType Size, Range (32bit)*
 
 그렇기 때문에 애초에 그 범위를 넘어서는 값은 변수에 대입할 수도 없다. 
 그리고 어떤 자료형이 표현할 수 있는 최대 범위에 근접한 숫자끼리 연산을 하면 오버플로우가 발생한다.

 따라서, 일일이 문자열로 저장해놨다가 한 자릿수씩 연산을 한다던가 별도의 방법으로 진행해야 한다.
