class OutputField extends React.Component {
    constructor(props) {
        super(props);
    }

    renderOutList = () => {
        let tempList = this.props.alph;
        let formattedList = [];
        tempList.forEach(function(ele, index) {
            formattedList.push(<div key={index}>{ele}</div>);
        })
        if(this.props.alph) {
            return (
                <div className="well">
                    {formattedList}
                </div>
            )
        }
        return (<div></div>);
    }

    startThingy = () => {
        return;
    }

    render() {
        return (
            <div>
                {this.renderOutList()}
            </div>
        )
    }
}