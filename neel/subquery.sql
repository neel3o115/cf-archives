select *
from 
    customers 
where 
    age > (select avg(age) from customers);

select c*
from 
    customers c
inner join 
    orders o on c.order_id = o.id and o.product_id = "i%";

select *
from 
    customers
where 
    customer_id in (
        select customer_id 
        from 
            orders
        where
            product_name like "%i"
    )

select
    customer_id,
    count(order_id)
from 
    orders
group by 
    customer_id
where 
    count(order_id) > 4;