SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

CREATE SCHEMA IF NOT EXISTS `srv` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci ;
USE `srv` ;

-- -----------------------------------------------------
-- Table `srv`.`persons`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `srv`.`persons` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `nombre` VARCHAR(25) NULL ,
  `apellidoP` VARCHAR(25) NULL ,
  `apellidoM` VARCHAR(25) NULL ,
  `sexo` CHAR(1) NULL DEFAULT 'M' ,
  `ruta_imagen` VARCHAR(45) NULL ,
  `ruta_WAV` VARCHAR(45) NULL ,
  PRIMARY KEY (`id`) ,
  UNIQUE INDEX `id_UNIQUE` (`id` ASC) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `srv`.`params`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `srv`.`params` (
  `idparams` INT NOT NULL ,
  `persons_id` INT NOT NULL ,
  `fo` FLOAT NULL COMMENT 'Fo /Hz/- Average fundamental frequency for the vocalization.' ,
  `to` FLOAT NULL COMMENT 'To /ms/ - Period, in miliseconds, of the average glottal period.' ,
  `fhi` FLOAT NULL COMMENT 'Fhi /Hz/-Highest Fundamental Frequency in vocalization.' ,
  `flo` FLOAT NULL COMMENT 'Flo /Hz/ - Lowest fundamental frequency in vocalization.' ,
  `STD` FLOAT NULL COMMENT 'STD /Hz/ - Standard Deviation of the fundamental frequency in the vocali-zation.' ,
  `PFR` FLOAT NULL COMMENT 'PFR - Phonatory Fundamental Frequency Range in Semi-tones' ,
  `Fftr` FLOAT NULL COMMENT 'Fftr /Hz/ - The frequency of the most intensive low-frequency Fo-modulating component.' ,
  `Fatr` FLOAT NULL COMMENT 'Fatr /Hz/ - The frequency of the most intensive low-frequency amplitude modulating component.' ,
  `Tsam` FLOAT NULL COMMENT 'Tsam /sec/ - Length of analyzed voice data sample in seconds.' ,
  `Jita` FLOAT NULL COMMENT 'Jita /us/- Absolute Jitter gives an evaluation of the period-to-period variability in microseconds of the pitch period within the analyzed voice sample.' ,
  `Jitt` FLOAT NULL COMMENT 'Jitt /%/ - Jitter Percent gives an evaluation of the variability of the pitch period within the analyzed voice sample in percent. It represents the relative period-to-period (very short-term) variability.' ,
  `RAP` FLOAT NULL COMMENT 'RAP /%/ - Relative Average Perturbation gives an evaluation of the variability of the pitch period within the analyzed voice sample at smoothing factor 3 periods.' ,
  `PPQ` FLOAT NULL COMMENT 'PPQ /%/ - Pitch Period Perturbation Quotient gives an evaluation in percent of the variability of the pitch period within the analyzed voice sample at smoothing factor 5 periods.' ,
  `sPPQ` FLOAT NULL COMMENT 'sPPQ /%/ - Smoothed Pitch Period Perturbation Quotient gives an evaluation in percent of the variability of the pitch period within the analyzed voice sample at smoothing factor 55 periods. ' ,
  `vFo` FLOAT NULL COMMENT 'vFo /%/- Fundamental Frequency Variation represents the relative standard deviation of the period-to-period calculated Fundamental Frequency. It reflects the very long-term variations of Fo for all the analyzed voice sample.' ,
  `shdB` FLOAT NULL COMMENT 'ShdB /dB/ - Shimmer in dB gives an evaluation  of the period-to-period variability  of the  peak-to-peak amplitude  within the analyzed voice sample.\n' ,
  `Shim` FLOAT NULL COMMENT 'Shim /%/ - Shimmer Percent gives an evaluation in percent of the variability of the peak-to-peak amplitude within the analyzed voice sample. It represents the relative period-to-period (very short-term) variability of the peak-to-peak amplitude.' ,
  `APQ` FLOAT NULL COMMENT 'APQ /%/ - Amplitude Perturbation Quotient gives an evaluation in percent of the variability of the peak-to-peak amplitude within the analyzed voice sample at smoothing factor 11 periods.' ,
  `sAPQ` FLOAT NULL ,
  `vAm` FLOAT NULL COMMENT 'vAm /%/ - Peak Amplitude Variation represents the relative standard deviation of the period-to-period calculated peak-to-peak amplitude. It reflects the very long-term amplitude variations within the analyzed voice sample.' ,
  `NHR` FLOAT NULL COMMENT 'NHR - Noise to Harmonic Ratio  is an average ratio  of energy of the in-harmonic components in the range 1500-4500Hz  to the harmonic components energy in the range 70-4500 Hz.' ,
  `VTI` FLOAT NULL COMMENT 'VTI - Voice Turbulence Index is an average ratio of the spectral in-harmonic high-frequency energy in the range 2800-5800Hz.' ,
  `SPI` FLOAT NULL COMMENT 'SPI - Soft Phonation Index is an average ratio of the lower-frequency (70-1600Hz) to the higher-frequency (1600-4500Hz) harmonic energy.' ,
  `FTRI` FLOAT NULL COMMENT 'FTRI /%/ - Fo-Tremor Intensity Index shows in percent the ratio of the frequency magnitude of the most intensive low-frequency modulating component ( Fo-tremor ) to the total frequency magnitude of the analyzed voice signal.' ,
  `ATRI` FLOAT NULL COMMENT 'ATRI /%/ - Amplitude Tremor Intensity Index shows in percent the ratio of the amplitude of the most intensive low-frequency amplitude modulating component (amplitude tremor) to the total amplitude of the analyzed voice signal.' ,
  `DVB` FLOAT NULL COMMENT 'DVB /%/ - Degree of Voice Breaks shows in percent the ratio of the total length of areas representing voice breaks to the time of the complete voice sample.' ,
  `DSH` FLOAT NULL COMMENT 'DSH /%/ - Degree of sub-harmonics is an estimated relative evaluation of sub-harmonic to Fo components in the voice sample.' ,
  `DUB` FLOAT NULL COMMENT 'DUV /%/ - Degree of Voiceless is an estimated relative evaluation of non-harmonic areas (where Fo can not be detected) in the voice sample.' ,
  `NVB` FLOAT NULL COMMENT 'NVB - Number of Voice Breaks shows how many times the generated Fo was interrupted from the beginning of the first until the end of the last voiced area.' ,
  `NSH` FLOAT NULL COMMENT 'NSH- Number of Sub-Harmonic Segments found during analysis. ' ,
  `NUV` FLOAT NULL COMMENT 'NSH- Number of Sub-Harmonic Segments found during analysis. ' ,
  `SEG` FLOAT NULL COMMENT 'SEG-Total number of segments computed during the MDVP- autocorrelation analysis.' ,
  `PER` FLOAT NULL COMMENT 'PER - Pitch Periods detected during the period-to-period pitch extraction using MDVP.' ,
  PRIMARY KEY (`idparams`) ,
  INDEX `fk_params_persons` (`persons_id` ASC) ,
  CONSTRAINT `fk_params_persons`
    FOREIGN KEY (`persons_id` )
    REFERENCES `srv`.`persons` (`id` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;



SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
