﻿ALTER TABLE `swgemu`.`character_items`
 ADD COLUMN `skillmod0_type` TINYINT NOT NULL DEFAULT 0 AFTER `sliced`,
 ADD COLUMN `skillmod0_value` TINYINT NOT NULL DEFAULT 0 AFTER `skillmod0_type`,
 ADD COLUMN `skillmod1_type` TINYINT NOT NULL DEFAULT 0 AFTER `skillmod0_value`,
 ADD COLUMN `skillmod1_value` TINYINT NOT NULL DEFAULT 0 AFTER `skillmod1_type`,
 ADD COLUMN `skillmod2_type` TINYINT NOT NULL DEFAULT 0 AFTER `skillmod1_value`,
 ADD COLUMN `skillmod2_value` TINYINT NOT NULL DEFAULT 0 AFTER `skillmod2_type`,
 ADD COLUMN `sockets` TINYINT NOT NULL DEFAULT 0 AFTER `skillmod2_value`,
 ADD COLUMN `socket0_type` TINYINT NOT NULL DEFAULT 0 AFTER `sockets`,
 ADD COLUMN `socket0_value` TINYINT NOT NULL DEFAULT 0 AFTER `socket0_type`,
 ADD COLUMN `socket1_type` TINYINT NOT NULL DEFAULT 0 AFTER `socket0_value`,
 ADD COLUMN `socket1_value` TINYINT NOT NULL DEFAULT 0 AFTER `socket1_type`,
 ADD COLUMN `socket2_type` TINYINT NOT NULL DEFAULT 0 AFTER `socket1_value`,
 ADD COLUMN `socket2_value` TINYINT NOT NULL DEFAULT 0 AFTER `socket2_type`,
 ADD COLUMN `socket3_type` TINYINT NOT NULL DEFAULT 0 AFTER `socket2_value`,
 ADD COLUMN `socket3_value` TINYINT NOT NULL DEFAULT 0 AFTER `socket3_type`
