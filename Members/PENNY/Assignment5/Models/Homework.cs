using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment5.Models
{
    public class Homework 
    {
        [Key]
        public int ID { get; set; }

        [Required]
        public string HomeworkPriority { get; set; }

        [Required]
        //Make your DateTime in the correct format(here I got some ideas online and from myclassmates)
        [DataType(DataType.DateTime)]
        [DisplayFormat(ApplyFormatInEditMode =true, DataFormatString ="{0:yyyy-MM-dd}")]
        public DateTime DueDate { get; set; }

        [Required]
       
        public TimeSpan DueTime { get; set; }

        [Required]
        public string Department { get; set; }

        [Required]
        public int Course { get; set; }

        [Required]
        public string HomeworkTitle { get; set; }

        [Required]
        public string Notes { get; set; }

        public override string ToString()
        {
            return $"{base.ToString()}: {HomeworkPriority} {DueDate} {DueTime} {Department} {Course} {HomeworkTitle} {Notes}";
        }
    }
}