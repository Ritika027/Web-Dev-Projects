const fs = require('fs');
const filePath = './tasks.json';

// Load tasks from the JSON file
const loadTasks = () => {
    try {
        const dataBuffer = fs.readFileSync(filePath);
        const dataJSON = dataBuffer.toString();
        return JSON.parse(dataJSON);
    } catch (error) {
        return [];
    }
};

// Save tasks to the JSON file
const saveTasks = (tasks) => {
    const dataJSON = JSON.stringify(tasks, null, 2);  // Pretty print the JSON with indentations
    fs.writeFileSync(filePath, dataJSON);
};

// Add a new task
const addTask = (task) => {
    const tasks = loadTasks();
    tasks.push({ task });
    saveTasks(tasks);
    console.log('Task added successfully:', task);
};

// List all tasks
const listTasks = () => {
    const tasks = loadTasks();  // Load the tasks from the file
    if (tasks.length === 0) {
        console.log('No tasks found!');
    } else {
        console.log('Your tasks:');
        tasks.forEach((task, index) => {
            console.log(`${index + 1}. ${task.task}`);  // Fixed template literal syntax
        });
    }
};

// Remove a task by its index
const removeTask = (index) => {
    const tasks = loadTasks();
    if (index >= 0 && index < tasks.length) {
        const removedTask = tasks.splice(index, 1);
        saveTasks(tasks);
        console.log('Task removed successfully:', removedTask[0].task);
    } else {
        console.log('Task not found.');
    }
};

// Command-line argument parsing
const command = process.argv[2];
const argument = process.argv[3];

// Handling commands
if (command === 'add') {
    if (argument) {
        addTask(argument);
    } else {
        console.log('Please provide a task to add.');
    }
} else if (command === 'list') {
    listTasks();
} else if (command === 'remove') {
    const taskIndex = parseInt(argument, 10);
    if (!isNaN(taskIndex) && taskIndex >= 1) {
        removeTask(taskIndex - 1);  // Subtract 1 to match array index
    } else {
        console.log('Please provide a valid task number to remove.');
    }
} else {
    console.log('Command not found!');
}
