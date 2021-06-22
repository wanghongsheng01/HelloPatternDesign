## FactoryPizzaFranchise Design Graph
![image](https://user-images.githubusercontent.com/31394900/122861375-ed2ea180-d351-11eb-8761-dfb422d39d8f.png)


## Show Result
```cpp
unique_ptr<NYPizzaStore> NYstore = make_unique<NYPizzaStore>();
cout<<"\n---order NYCheesePizza---\n"<<endl;
unique_ptr<Pizza> NYCheesePizza = NYstore->orderPizza("Cheese");
cout<<*NYCheesePizza;
```

---order NYCheesePizza---<br>

Pizza::prepare()...<br>
preparingNYStyle Cheese Pizza<br>
Pizza::bake()...<br>
baking NYStyle Cheese Pizza<br>
Pizza::cut()...<br>
cuting NYStyle Cheese Pizza<br>
Pizza::box()...<br>
boxing NYStyle Cheese Pizza<br>

----- NYStyle Cheese Pizza -----<br>
NYStyle Cheese Pizza's Doue<br>
NYStyle Cheese Pizza's Sauce<br>
NYStyle Cheese Pizza's topping style1<br>
NYStyle Cheese Pizza's topping style2<br>


---order ChicagoCheesePizza---<br>

Pizza::prepare()...<br>
preparingChicago Style Cheese Pizza<br>
Pizza::bake()...<br>
baking Chicago Style Cheese Pizza<br>
Pizza::cut()...<br>
cuting Chicago Style Cheese Pizza<br>
Pizza::box()...<br>
boxing Chicago Style Cheese Pizza<br>

----- Chicago Style Cheese Pizza -----
Chicago Style Cheese Pizza's Doue<br>
Chicago Style Cheese Pizza's Sauce<br>
Chicago Style Cheese Pizza's topping style1<br>
Chicago Style Cheese Pizza's topping style2<br>


---order ChicagoPepperoniPizza---<br>

Pizza::prepare()...<br>
preparingChicago Style Pepperoni Pizza<br>
Pizza::bake()...<br>
baking Chicago Style Pepperoni Pizza<br>
Pizza::cut()...<br>
cuting Chicago Style Pepperoni Pizza<br>
Pizza::box()...<br>
boxing Chicago Style Pepperoni Pizza<br>

----- Chicago Style Pepperoni Pizza -----<br>
Chicago Style Pepperoni Pizza's Doue<br>
Chicago Style Pepperoni Pizza's Sauce<br>
Chicago Style Pepperoni Pizza's topping style1<br>
Chicago Style Pepperoni Pizza's topping style2<br>


---order ChicagoVeggiePizza---<br>

Pizza::prepare()...<br>
preparingChicago Style Veggie Pizza<br>
Pizza::bake()...<br>
baking Chicago Style Veggie Pizza<br>
Pizza::cut()...<br>
cuting Chicago Style Veggie Pizza<br>
Pizza::box()...<br>
boxing Chicago Style Veggie Pizza<br>

----- Chicago Style Veggie Pizza -----<br>
Chicago Style Veggie Pizza's Doue<br>
Chicago Style Veggie Pizza's Sauce<br>
Chicago Style Veggie Pizza's topping style1<br>
Chicago Style Veggie Pizza's topping style2<br>

