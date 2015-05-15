REGEXP_DIGIT = /[0-9]/;
REGEXP_UPPER = /[A-Z]/;
REGEXP_LOWER = /[a-z]/;
REGEXP_PUNCT = /[!"#$%&'()*+,\-./:;<=>?@[\\\]^_`{|}~]/;
REGEXP_LEGAL_CHAR = /[A-Za-z0-9!"#$%&'()*+,\-./:;<=>?@[\\\]^_`{|}~]/g;

/**
 * validatePasswordByRule
 */

validatePasswordByRule = function(min, max, ruleId, pswd) {
  var len = pswd.length;
  if (!(len >= min && len <= max)) {
    return {result:false, msg: "密码长度范围须为" + min + "~" + max};
  }

  if (pswd.replace(REGEXP_LEGAL_CHAR, "").length != 0) {
    return {result:false, msg: "密码不允许含有特殊字符"};
  }

  var hasDigit = {reg: REGEXP_DIGIT, errorMsg: "密码须包含数字"};
  var hasUpper = {reg: REGEXP_UPPER, errorMsg: "密码须包含大写字母"};
  var hasLower = {reg: REGEXP_LOWER, errorMsg: "密码须包含小写字母"};
  var hasPunct = {reg: REGEXP_PUNCT, errorMsg: "密码须包含标点符号"};

  var rules = [];
  rules[0] = [];
  rules[1] = [hasDigit];
  rules[2] = [hasUpper, hasLower];
  rules[3] = [hasDigit, hasUpper, hasLower];
  rules[4] = [hasDigit, hasUpper, hasLower, hasPunct];

  var rule = rules[ruleId];

  for (var i = 0, n = rule.length; i < n; i++) {
    var obj = rule[i];
    if (!obj["reg"].test(pswd)) {
      return {result:false, msg: obj["errorMsg"]};
    }
  }

  var hasRepeat = "([A-Za-z0-9!\"#$%&'()*+,\\\-./:;<=>?@[\\\\\\]^_`{|}~])\\1{count,}";
  var reg = new RegExp(hasRepeat.replace(/count/, 3));
  if (reg.test(pswd)) {
    return {result: false, msg: "密码有太多重复字符"};
  }

  return {result: true, msg: "密码符合规则"};
};
