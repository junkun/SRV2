CREATE DATABASE  IF NOT EXISTS `srv` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `srv`;
-- MySQL dump 10.13  Distrib 5.1.40, for Win32 (ia32)
--
-- Host: 127.0.0.1    Database: srv
-- ------------------------------------------------------
-- Server version	5.5.8

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
-- Table structure for table `persons`
--

DROP TABLE IF EXISTS `persons`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `persons` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(25) DEFAULT NULL,
  `apellidos` varchar(25) DEFAULT NULL,
  `edad` tinyint(9) DEFAULT NULL,
  `sexo` char(1) DEFAULT 'M',
  `ruta_imagen` varchar(45) DEFAULT NULL,
  `ruta_WAV` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `persons`
--

LOCK TABLES `persons` WRITE;
/*!40000 ALTER TABLE `persons` DISABLE KEYS */;
INSERT INTO `persons` VALUES (1,'test1','test1',63,'F',NULL,NULL),(2,'test2','test2',19,'M',NULL,NULL),(3,'test3','test3',25,'F',NULL,NULL),(4,'test4','test4',39,'F',NULL,NULL),(5,'normal1','normal1',29,'F',NULL,NULL),(6,'normal2','normal2',34,'M',NULL,NULL),(7,'normal3','alergia1',37,'M',NULL,NULL),(8,'normal4','alergia2',NULL,'M',NULL,NULL);
/*!40000 ALTER TABLE `persons` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `params`
--

DROP TABLE IF EXISTS `params`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `params` (
  `idparams` int(11) NOT NULL,
  `persons_id` int(11) NOT NULL,
  `Fo` float DEFAULT NULL COMMENT 'Fo /Hz/- Average fundamental frequency for the vocalization.',
  `To` float DEFAULT NULL COMMENT 'To /ms/ - Period, in miliseconds, of the average glottal period.',
  `Fhi` float DEFAULT NULL COMMENT 'Fhi /Hz/-Highest Fundamental Frequency in vocalization.',
  `Flo` float DEFAULT NULL COMMENT 'Flo /Hz/ - Lowest fundamental frequency in vocalization.',
  `STD` float DEFAULT NULL COMMENT 'STD /Hz/ - Standard Deviation of the fundamental frequency in the vocali-zation.',
  `PFR` float DEFAULT NULL COMMENT 'PFR - Phonatory Fundamental Frequency Range in Semi-tones',
  `Fftr` float DEFAULT NULL COMMENT 'Fftr /Hz/ - The frequency of the most intensive low-frequency Fo-modulating component.',
  `Fatr` float DEFAULT NULL COMMENT 'Fatr /Hz/ - The frequency of the most intensive low-frequency amplitude modulating component.',
  `Tsam` float DEFAULT NULL COMMENT 'Tsam /sec/ - Length of analyzed voice data sample in seconds.',
  `Jita` float DEFAULT NULL COMMENT 'Jita /us/- Absolute Jitter gives an evaluation of the period-to-period variability in microseconds of the pitch period within the analyzed voice sample.',
  `Jitt` float DEFAULT NULL COMMENT 'Jitt /%/ - Jitter Percent gives an evaluation of the variability of the pitch period within the analyzed voice sample in percent. It represents the relative period-to-period (very short-term) variability.',
  `RAP` float DEFAULT NULL COMMENT 'RAP /%/ - Relative Average Perturbation gives an evaluation of the variability of the pitch period within the analyzed voice sample at smoothing factor 3 periods.',
  `PPQ` float DEFAULT NULL COMMENT 'PPQ /%/ - Pitch Period Perturbation Quotient gives an evaluation in percent of the variability of the pitch period within the analyzed voice sample at smoothing factor 5 periods.',
  `sPPQ` float DEFAULT NULL COMMENT 'sPPQ /%/ - Smoothed Pitch Period Perturbation Quotient gives an evaluation in percent of the variability of the pitch period within the analyzed voice sample at smoothing factor 55 periods.  sPPQ correlates with the intensity of the long-term pitch period variations,such as frequency tremors. ',
  `vFo` float DEFAULT NULL COMMENT 'vFo /%/- Fundamental Frequency Variation represents the relative standard deviation of the period-to-period calculated Fundamental Frequency. It reflects the very long-term variations of Fo for all the analyzed voice sample.',
  `shdB` float DEFAULT NULL COMMENT 'ShdB /dB/ - Shimmer in dB gives an evaluation  of the period-to-period variability  of the  peak-to-peak amplitude  within the analyzed voice sample.\n',
  `Shim` float DEFAULT NULL COMMENT 'Shim /%/ - Shimmer Percent gives an evaluation in percent of the variability of the peak-to-peak amplitude within the analyzed voice sample. It represents the relative period-to-period (very short-term) variability of the peak-to-peak amplitude.',
  `APQ` float DEFAULT NULL COMMENT 'APQ /%/ - Amplitude Perturbation Quotient gives an evaluation in percent of the variability of the peak-to-peak amplitude within the analyzed voice sample at smoothing factor 11 periods.',
  `sAPQ` float DEFAULT NULL COMMENT 'sAPQ /%/ - Amplitude Perturbation Quotient gives an evaluation in percent of the variability of the peak-to-peak amplitude within the analyzed voice sample at smoothing factor 55 periods. sAPQ correlates with the intensity of the long-term peak-to-peak amplitude variations, such as amplitude tremors. ',
  `vAm` float DEFAULT NULL COMMENT 'vAm /%/ - Peak Amplitude Variation represents the relative standard deviation of the period-to-period calculated peak-to-peak amplitude. It reflects the very long-term amplitude variations within the analyzed voice sample.',
  `NHR` float DEFAULT NULL COMMENT 'NHR - Noise to Harmonic Ratio  is an average ratio  of energy of the in-harmonic components in the range 1500-4500Hz  to the harmonic components energy in the range 70-4500 Hz. It is a general evaluation of the noise presence in the analyzed signal (such as amplitude and frequency variations, turbulence noise, sub-harmonic components and/or voice breaks).',
  `VTI` float DEFAULT NULL COMMENT 'VTI - Voice Turbulence Index is an average ratio of the spectral in-harmonic high-frequency energy in the range 2800-5800Hz to the spectral harmonic energy in the range 70-4500Hz in areas of the signal where the influence of the fre-quency and amplitude variations, voice breaks and subharmonic components are minimal. VTI measures the relative energy level of high-frequency noise. It mostly correlates with the turbulence caused by incomplete or loose adduction of the vocal folds.',
  `SPI` float DEFAULT NULL COMMENT 'SPI - Soft Phonation Index is an average ratio of the lower-frequency (70-1600Hz) to the higher-frequency (1600-4500Hz) harmonic energy. Increased value of SPI may be an indication of loosely adducted vocal folds during phonation. SPI is very sensitive to the vowel formant structure, because vowels with lower high-fre-quency energy will result in higher SPI. Only values computed for the same vowel can be compared. This index is not a measurement of abnormality but rather a measurement of the spectral "type" of the vocalization.',
  `FTRI` float DEFAULT NULL COMMENT 'FTRI /%/ - Fo-Tremor Intensity Index shows in percent the ratio of the frequency magnitude of the most intensive low-frequency modulating component ( Fo-tremor ) to the total frequency magnitude of the analyzed voice signal.',
  `ATRI` float DEFAULT NULL COMMENT 'ATRI /%/ - Amplitude Tremor Intensity Index shows in percent the ratio of the amplitude of the most intensive low-frequency amplitude modulating component (amplitude tremor) to the total amplitude of the analyzed voice signal.',
  `DVB` float DEFAULT NULL COMMENT 'DVB /%/ - Degree of Voice Breaks shows in percent the ratio of the total length of areas representing voice breaks to the time of the complete voice sample.',
  `DSH` float DEFAULT NULL COMMENT 'DSH /%/ - Degree of sub-harmonics is an estimated relative evaluation of sub-harmonic to Fo components in the voice sample.',
  `DUB` float DEFAULT NULL COMMENT 'DUV /%/ - Degree of Voiceless is an estimated relative evaluation of non-harmonic areas (where Fo can not be detected) in the voice sample. In case of non-sustained phonation from the beginning to the end of the data acquisition, DUV will evaluate also the pauses before, after and/or between the voice sample(s).',
  `NVB` float DEFAULT NULL COMMENT 'NVB - Number of Voice Breaks shows how many times the generated Fo was interrupted from the beginning of the first until the end of the last voiced area.',
  `NSH` float DEFAULT NULL COMMENT 'NSH- Number of Sub-Harmonic Segments found during analysis. ',
  `NUV` float DEFAULT NULL COMMENT 'NSH- Number of Sub-Harmonic Segments found during analysis. ',
  `SEG` float DEFAULT NULL COMMENT 'SEG-Total number of segments computed during the MDVP- autocorrelation analysis.',
  `PER` float DEFAULT NULL COMMENT 'PER - Pitch Periods detected during the period-to-period pitch extraction using MDVP.',
  PRIMARY KEY (`idparams`),
  KEY `fk_params_persons` (`persons_id`),
  CONSTRAINT `fk_params_persons` FOREIGN KEY (`persons_id`) REFERENCES `persons` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `params`
--

LOCK TABLES `params` WRITE;
/*!40000 ALTER TABLE `params` DISABLE KEYS */;
INSERT INTO `params` VALUES (1001,1,243.091,4.114,248.262,237.417,2.045,2,4.124,2.151,1.008,26.942,0.655,0.4,0.37,0.564,0.841,0.447,5.173,3.893,6.643,9.127,0.107,0.021,23.7948,0.298,5.254,0,0,0,0,0,0,0,0),(1002,2,114.606,8.726,116.686,112.892,0.79,2,5.714,NULL,1.032,68.345,0.783,0.456,0.475,0.561,0.689,0.272,3.138,2.349,4.788,6.964,0.169,0.051,8.346,0.199,0.239,0,0,0,0,0,0,0,0),(1003,3,167.23,5.98,170.648,163.773,1.501,2,4.762,5.882,0.999,65.948,1.103,0.635,0.708,0.715,0.898,0.544,6.36,5.119,8.371,11.704,0.185,0.077,11.43,0.176,5.23,0,3.448,6.452,0,1,2,0,0),(1004,4,185.715,5.397,203.252,156.986,8.946,5,3.738,3.67,1.005,310.71,5.757,3.489,3.415,3.721,4.817,1.032,11.883,8.329,11.8,20.38,0.274,0.087,12.02,1.199,9.824,0,30.435,25.806,0,7,8,0,0),(1005,5,239.655,4.173,244.858,232.234,2.246,2,5.634,NULL,3,21.324,0.511,0.306,0.29,0.471,0.937,0.109,1.245,0.915,1.361,9.032,0.109,0.025,5.309,0.401,0,0,0,0,0,0,0,0,0),(1006,6,151.566,6.599,156.201,146.477,1.761,3,1.66,2.381,3,35.241,0.534,0.322,0.299,0.584,1.162,0.185,2.132,1.518,2.824,6.104,0.129,0.085,3.176,0.518,1.007,0,0,0,0,0,0,0,0),(1007,7,121.805,8.211,126.358,116.604,1.627,2,1.606,1.008,3,115.368,1.405,0.849,0.793,0.897,1.336,0.236,2.703,1.914,2.441,4.749,0.117,0.045,8.551,0.382,1.275,0,0,1.053,0,0,1,0,0),(1008,8,240.348,4.161,249.626,232.45,2.97,3,1.067,1.515,3,44.194,1.062,0.641,0.611,0.896,1.236,0.354,3.814,2.678,5.001,25.886,0.12,0.05,11.617,0.404,3.927,0,0,0,0,0,0,0,0),(1009,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
/*!40000 ALTER TABLE `params` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2011-03-14 16:41:38
