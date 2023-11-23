
/*FIND NEW CUSTOMERS ADDED PER MONTH*/

with cte as (
  select order_date,customer_id,qty,row_number() 
  over (partition by customer order by order_date) 
  rnk from sales)
select order_date,count(rnk) from cte where 
rnk = 1 group by order_date;


/*FIND SOURCE AND DESTINATION OF CUSTOMER*/

select a.cid,a.origin,b.destination from 
flights a left join flights b on a.cid = b.cid 
and a.destination = b.origin where b.destination is not null;
