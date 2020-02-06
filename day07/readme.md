# 向上向下类型转换
           Anmixl
    Cat              Dog

## 不发生多态
	Animal * anmial = new Animal;
	Cat * cat = (Cat *)Animal;

向下类型转换不安全（基类转派生类不安全）  （基类 小于 派生类）


    Cat * cat = new Cat;
	Animal * anmial = new (Animal *)cat;;
向上类型转换安全   （派生类转基类）

## 发生多态
如果发生多态，总是安全的。

Animal * anmial = new Cat;

