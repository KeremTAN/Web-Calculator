import React  from 'react';
import CalculatorButton from './CalculatorButton';
import CalculatorDisplay from './CalculatorDisplay';

function CalculatorPanel(props) {

    const captions = [
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "C", "+",
        "=",
    ]

    const calc_buttons = captions.map((value, index) => {
        return <CalculatorButton caption={value} />
    });

    return (
        <div className='calculator-grid-container'>
            <CalculatorDisplay />
            {calc_buttons}
        </div>
    )
}

export default CalculatorPanel;