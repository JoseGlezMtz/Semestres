## Components

Javascript function that returns HTML (jsx markup)

Some FEatures:
- Their name must start with capital letter
- components can render other components
- Types: class And functional

__Hooks__

 Function that allows to create and access React state ind lifecycle

 useState: The value given to the hook is the initial state

 useEffect: Performs side effects in the function components after every render

```js
import {useState} from "react"

function Counter(){
    const {count, setCount}= useState(0)

    const Increment = () => {
        setCount (count + 1);
    }
    const Decrement= () => {
        setCount (count - 1);
    }
    return (
        <div>
        <p> count: {count}</p>
        <button onClick ={Increment}>increment</button>
        <button onClick ={Decrement}>Decrement</button>
    )
}

```

