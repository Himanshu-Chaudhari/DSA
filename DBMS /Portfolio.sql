-- use Portfolio;
INSERT INTO Stocks VALUES( 1234,"xyz",2008-10-2,123,10); 
-- select * from Stocks;
-- create table Sum_calculated

-- DROP TRIGGER IF EXISTS total_on_insert;


-- DELIMITER //
-- CREATE TRIGGER total_on_insert
-- AFTER INSERT ON Stocks
-- FOR EACH ROW
-- BEGIN
--     -- Calculate age based on the Date of Birth (DOB) and the current date
--     DECLARE total INT;
--     SET total = sum(purchsePrices);

--     -- Insert the calculated age into the "age" table
--     INSERT INTO Sum_calculated 
--     VALUES (NEW.DMAT_no, total);
-- END;
-- //
-- DELIMITER ;



DELIMITER //
CREATE TRIGGER calc_age_on_insert
AFTER INSERT ON holder2
FOR EACH ROW
BEGIN
    -- Calculate age based on the Date of Birth (DOB) and the current date
    DECLARE age_calculation INT;
    SET age_calculation = TIMESTAMPDIFF(YEAR, NEW.dob, CURDATE());

    -- Insert the calculated age into the "age" table
    INSERT INTO age 
    VALUES (NEW.name, age_calculation);
END;
//
DELIMITER ;






DELIMITER //
CREATE PROCEDURE qualified()
begin
select * from age where age>18;
end
//
DELIMITER ;
insert into age values ("user3", 56 );
insert into age values ("user7", 19 );
insert into age values ("user19", 51 );
insert into age values ("user3", 5 );
call qualified();

-- Create a function to calculate the average age

DELIMITER //
CREATE FUNCTION CalculateAverageAge()
RETURNS DECIMAL(10, 2)
BEGIN
  DECLARE total_age DECIMAL(10, 2);
  DECLARE total_count INT;
  DECLARE average_age DECIMAL(10, 2);
  
  -- Initialize variables
  SET total_age = 0;
  SET total_count = 0;

  -- Calculate the sum of ages and the count of records
  SELECT SUM(age), COUNT(*) INTO total_age, total_count FROM age;

  -- Calculate the average age
  IF total_count > 0 THEN
    SET average_age = total_age / total_count;
  ELSE
    SET average_age = 0;
  END IF;

  RETURN average_age;
END;
//
DELIMITER ;

-- use Portfolio;
-- -- Create the StocksTotalPrice table if not exists
-- CREATE TABLE IF NOT EXISTS StocksTotalPrice (
--     DMAT_no VARCHAR(30) PRIMARY KEY,
--     TotalPrice INT
-- );

-- -- Create the trigger
-- DELIMITER //
-- CREATE TRIGGER calculate_total_price
-- AFTER INSERT ON Stocks
-- FOR EACH ROW
-- BEGIN
--     -- Declare variables to store total price
--     DECLARE total_price INT;

--     -- Calculate total price based on purchased price and insert into StocksTotalPrice table
--     SELECT SUM(purchasePrice) INTO total_price
--     FROM Stocks
--     WHERE DMAT_no = NEW.DMAT_no;

--     -- Insert or update the total price in StocksTotalPrice table
--     INSERT INTO StocksTotalPrice (DMAT_no, TotalPrice)
--     VALUES (NEW.DMAT_no, total_price)
--     ON DUPLICATE KEY UPDATE TotalPrice = total_price;
-- END;
-- //
-- DELIMITER ;

select * from StocksTotalPrice;

-- Create a stored procedure
-- DELIMITER //
-- CREATE PROCEDURE ProcessStocks()
-- BEGIN
--     -- Declare variables
--     DECLARE done INT DEFAULT FALSE;
--     DECLARE dmat_no_var VARCHAR(30);
--     DECLARE purchase_price_var INT;

--     -- Declare the cursor
--     DECLARE stock_cursor CURSOR FOR
--         SELECT DMAT_no, purchasePrice
--         FROM Stocks;

--     -- Declare continue handler
--     DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

--     -- Open the cursor
--     OPEN stock_cursor;

--     -- Start fetching and processing rows
--     read_loop: LOOP
--         -- Fetch the next row into variables
--         FETCH stock_cursor INTO dmat_no_var, purchase_price_var;

--         -- Check if no more rows to fetch
--         IF done THEN
--             LEAVE read_loop;
--         END IF;

--         -- Perform operations with fetched data (you can modify this part)
--         -- In this example, printing the DMAT_no and purchasePrice
--         SELECT CONCAT('DMAT_no: ', dmat_no_var, ', Purchase Price: ', purchase_price_var) AS Result;

--     END LOOP;

--     -- Close the cursor
--     CLOSE stock_cursor;
-- END //
-- DELIMITER ;

CALL ProcessStocks();


