
delimiter $$
drop procedure ff$$
CREATE PROCEDURE `ff`(in n int,out x varchar(20))
BEGIN
declare i int;
set i=1;
set x="";
lab1: loop
if i=n then leave lab1;
else 
set x=concat(x,i,',');
set i=i+1;
iterate lab1;
end if;
end loop;
END
$$



call ff(5,@x)$$

select @x$$

delimiter ;
