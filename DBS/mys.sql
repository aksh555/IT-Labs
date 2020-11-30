-- MySQL dump 10.13  Distrib 5.7.28, for Linux (x86_64)
--
-- Host: localhost    Database: company
-- ------------------------------------------------------
-- Server version	5.7.28-0ubuntu0.18.04.4

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `company`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `company` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `company`;

--
-- Table structure for table `department`
--

DROP TABLE IF EXISTS `department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `department` (
  `Dname` varchar(10) DEFAULT NULL,
  `Dno` tinyint(4) NOT NULL,
  `Mgr_ssn` char(9) DEFAULT NULL,
  `Mgr_start_dt` date DEFAULT NULL,
  PRIMARY KEY (`Dno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department`
--

LOCK TABLES `department` WRITE;
/*!40000 ALTER TABLE `department` DISABLE KEYS */;
INSERT INTO `department` VALUES ('HQ',1,'88866555','1981-06-19'),('Admin',4,'987654321','1995-01-01'),('Research',5,'333445555','1988-05-22');
/*!40000 ALTER TABLE `department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `department_loc`
--

DROP TABLE IF EXISTS `department_loc`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `department_loc` (
  `Dno` tinyint(4) NOT NULL,
  `Dloc` varchar(20) DEFAULT NULL,
  KEY `Dno` (`Dno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department_loc`
--

LOCK TABLES `department_loc` WRITE;
/*!40000 ALTER TABLE `department_loc` DISABLE KEYS */;
INSERT INTO `department_loc` VALUES (1,'Houston'),(4,'Stafford'),(5,'Bellaire');
/*!40000 ALTER TABLE `department_loc` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dependent`
--

DROP TABLE IF EXISTS `dependent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dependent` (
  `Essn` char(9) DEFAULT NULL,
  `Dep_name` varchar(10) DEFAULT NULL,
  `Sex` char(1) DEFAULT NULL,
  `Bdate` date DEFAULT NULL,
  `Relationship` varchar(10) DEFAULT NULL,
  KEY `Essn` (`Essn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dependent`
--

LOCK TABLES `dependent` WRITE;
/*!40000 ALTER TABLE `dependent` DISABLE KEYS */;
INSERT INTO `dependent` VALUES ('333445555','Alice','F','1986-04-05','Daughter'),('333445555','Theodore','M','1983-04-05','Son'),('123456789','Alice','F','1993-04-05','Daughter');
/*!40000 ALTER TABLE `dependent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `employee` (
  `Fname` varchar(15) DEFAULT NULL,
  `Minit` char(1) DEFAULT NULL,
  `Lname` varchar(10) DEFAULT NULL,
  `Ssn` char(9) NOT NULL,
  `Bdate` date DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  `Sex` char(1) DEFAULT NULL,
  `Salary` int(11) DEFAULT NULL,
  `Super_ssn` char(9) DEFAULT NULL,
  `Dno` tinyint(4) DEFAULT NULL,
  PRIMARY KEY (`Ssn`),
  KEY `Dno` (`Dno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
INSERT INTO `employee` VALUES ('John','B','Smith','123456789','1995-01-09','fe sdbefh fjrfji','M',30000,'333445555',5),('Franklin','B','Wong','333445555','1999-01-09','fe sdbefh fjrfji','F',90000,'888665555',5);
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `project`
--

DROP TABLE IF EXISTS `project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `project` (
  `Pname` varchar(20) DEFAULT NULL,
  `Pno` tinyint(4) NOT NULL,
  `Plocation` varchar(20) DEFAULT NULL,
  `Dno` tinyint(4) DEFAULT NULL,
  PRIMARY KEY (`Pno`),
  KEY `Dno` (`Dno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `project`
--

LOCK TABLES `project` WRITE;
/*!40000 ALTER TABLE `project` DISABLE KEYS */;
INSERT INTO `project` VALUES ('productx',1,'Bellaire',5),('producty',2,'Houston',5),('productz',3,'Stafford',4);
/*!40000 ALTER TABLE `project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `works_on`
--

DROP TABLE IF EXISTS `works_on`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `works_on` (
  `essn` char(9) NOT NULL,
  `Pno` tinyint(4) DEFAULT NULL,
  `Hours` float DEFAULT NULL,
  KEY `Pno` (`Pno`),
  KEY `essn` (`essn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `works_on`
--

LOCK TABLES `works_on` WRITE;
/*!40000 ALTER TABLE `works_on` DISABLE KEYS */;
INSERT INTO `works_on` VALUES ('123456789',1,22.5),('123456789',2,2.5),('333445555',3,8.5),('333445555',2,1.5);
/*!40000 ALTER TABLE `works_on` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-01-23 10:08:15
