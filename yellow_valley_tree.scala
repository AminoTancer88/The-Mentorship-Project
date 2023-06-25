import scala.collection.mutable.ArrayBuffer
 
object AtRiskYouthProgram {
 
    def main(args : Array[String]) {
 
        // create an array to hold data about the at-risk youth
        var atRiskYouthInfo = ArrayBuffer[AtRiskYouth]()
 
        // loop until the user wishes to quit
        var shouldContinue = true
        while (shouldContinue) {
 
            println("What would you like to do?\n1. Add New At-Risk Youth\n2. Remove At-Risk Youth\n3. Display At-Risk Youth List\n4. Quit")
 
            // get the user's input
            val option = scala.io.StdIn.readInt()
 
            // call the appropriate method based on the user's input
            option match {
 
                // add a new at-risk youth
                case 1 => addNewAtRiskYouth(atRiskYouthInfo)
 
                // remove an at-risk youth
                case 2 => removeAtRiskYouth(atRiskYouthInfo)
 
                // display the list of at-risk youth
                case 3 => displayAtRiskYouthList(atRiskYouthInfo)
 
                // quit
                case 4 => shouldContinue = false
 
                // if the user's input is not one of the options, print an error message
                case _ => println("Unexpected input. Please try again.")
            }
        }
    }
 
    // add a new at-risk youth to the list
    def addNewAtRiskYouth(atRiskYouthInfo : ArrayBuffer[AtRiskYouth]) {
        // get the information about the at-risk youth
        println("Input information about the at-risk youth below:")
        val name = readString("Name: ")
        val age = readInt("Age: ")
        val gender = readString("Gender: ")
        val school = readString("School: ")
 
        // create a new at-risk youth object and add it to the array
        val newAtRiskYouth = AtRiskYouth(name, age, gender, school)
        atRiskYouthInfo += newAtRiskYouth
 
        println("At-risk youth added successfully.")
    }
 
    // remove an at-risk youth from the list
    def removeAtRiskYouth(atRiskYouthInfo : ArrayBuffer[AtRiskYouth]) {
        // get the name of the at-risk youth to be removed
        println("Input the name of the at-risk youth to be removed:")
        val name = readString("Name: ")
 
        // search for the at-risk youth by name
        val index = atRiskYouthInfo.indexWhere(_.name == name)
 
        // if the at-risk youth is found, remove them from the array
        if (index >= 0) {
            atRiskYouthInfo.remove(index)
            println("At-risk youth removed successfully.")
        }
        // otherwise, print an error message
        else {
            println("At-risk youth not found.")
        }
    }
 
    // display the list of at-risk youth
    def displayAtRiskYouthList(atRiskYouthInfo : ArrayBuffer[AtRiskYouth]) {
        if (atRiskYouthInfo.isEmpty) {
            println("At-risk youth list is empty.")
        }
        else {
            println("At-Risk Youth Information")
            atRiskYouthInfo.foreach { atRiskYouth =>
                println("Name: " + atRiskYouth.name)
                println("Age: " + atRiskYouth.age)
                println("Gender: " + atRiskYouth.gender)
                println("School: " + atRiskYouth.school)
            }
        }
    }
 
    // read a string from the user
    def readString(prompt : String) : String = {
        println(prompt)
        return scala.io.StdIn.readLine()
    }
 
    // read an integer from the user
    def readInt(prompt : String) : Int = {
        println(prompt)
        try {
            return scala.io.StdIn.readInt()
        }
        catch {
            case e : Exception => { 
                println("Unexpected input. Please try again.")
                return readInt(prompt)
            }
        }
    }
 
    // AtRiskYouth class to store data about an individual at-risk youth
    case class AtRiskYouth(name : String, age : Int, gender : String, school : String)
}